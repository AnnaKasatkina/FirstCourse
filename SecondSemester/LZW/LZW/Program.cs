public class LZW
{
    public static void Compress(string inputFilePath, string outputFilePath)
    {

    }

    public static void Decompress(string inputFilePath, string outputFilePath)
    {

    }
}

class Program
{
    static void Main(string[] args)
    {
        if (args.Length != 2)
        {
            Console.WriteLine("Usage: LZWCompressionApp.exe <file_path> <-c or -u>");
            return;
        }

        string filePath = args[0];
        string key = args[1];

        LZW lzw = new LZW();
        //lzw.Run(filePath, key);
    }
}
