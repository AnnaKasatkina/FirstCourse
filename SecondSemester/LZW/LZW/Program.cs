public class LZW
{
    private Trie dictionary;

    public LZW()
    {
        dictionary = new Trie();
        InitializeDictionary();
    }

    private void InitializeDictionary()
    {
        for (int i = 0; i < 256;  i++)
        {
            dictionary.Add(((char)i).ToString());
        }
    }

    public void Run(string filePath, string key)
    {
        if (key == "-c")
        {
            Compress(filePath, filePath + ".zipped");
            CalculateCompressionRatio(filePath, filePath + ".zipped");
        }
        else if (key == "-u")
        {
            Decompress(filePath, filePath.Substring(0, filePath.Length - 7));
        }
        else
        {
            Console.WriteLine("Invalid key. Please use -c to compress or -u to decompress.");
        }
    }

    private void Compress(string inputFilePath, string outputFilePath)
    {
        byte[] inputBytes = File.ReadAllBytes(inputFilePath);
        List<int> compressedData = new List<int>();

        string currentString = string.Empty;
        foreach (byte currentByte in inputBytes)
        {
            char currentChar = (char)currentByte;
            string newCurrentString = currentString + currentChar;

            if (dictionary.Contains(newCurrentString))
            {
                currentString = newCurrentString;
            }
            else
            {
                compressedData.Add(dictionary.HowManyStartsWithPrefix(currentString));
                dictionary.Add(newCurrentString);
                currentString = currentChar.ToString();
            }
        }

        if (!string.IsNullOrEmpty(currentString))
        {
            compressedData.Add(dictionary.HowManyStartsWithPrefix(currentString));
        }

        File.WriteAllBytes(outputFilePath, IntListToByteArray(compressedData));
    }

    private byte[] IntListToByteArray(List<int> intList)
    {
        List<byte> byteArray = new List<byte>();
        foreach (int value in intList)
        {
            byteArray.Add((byte)value);
        }

        return byteArray.ToArray();
    }

    private void CalculateCompressionRatio(string originalFilePath, string compressedFilePath)
    {
        long originalSize = new FileInfo(originalFilePath).Length;
        long compressedSize = new FileInfo(compressedFilePath).Length;

        double compressionRatio = (double)originalSize / compressedSize;

        Console.WriteLine($"Compression Ratio: {compressionRatio:F2}");
    }

    private void Decompress(string inputFilePath, string outputFilePath)
    {
        byte[] compressedData = File.ReadAllBytes(inputFilePath);
        List<string> dictionaryList = new List<string>();
        InitializeDictionaryList(dictionaryList);

        using (MemoryStream outputMemoryStream = new MemoryStream())
        {
            using (BinaryWriter writer = new BinaryWriter(outputMemoryStream))
            {
                foreach (byte codeByte in compressedData)
                {
                    int code = codeByte;
                    string entry = dictionaryList[code];

                    foreach (char character in entry)
                    {
                        writer.Write((byte)character);
                    }

                    if (dictionaryList.Count <= 4096)
                    {
                        string newEntry = entry + entry[0];
                        dictionaryList.Add(newEntry);
                    }
                }
            }

            File.WriteAllBytes(outputFilePath, outputMemoryStream.ToArray());
        }
    }

    private void InitializeDictionaryList(List<string> dictionaryList)
    {
        for (int i = 0; i < 256; i++)
        {
            dictionaryList.Add(((char)i).ToString());
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        if (args.Length != 2)
        {
            Console.WriteLine("Input error!");
            return;
        }

        string filePath = args[0];
        string key = args[1];

        LZW lzw = new LZW();
        lzw.Run(filePath, key);
    }
}
