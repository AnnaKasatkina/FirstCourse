/// <summary>
/// The main program class for testing LZW compression and decompression.
/// </summary>
internal class Program
{
    private static void Main(string[] args)
    {
        if (args.Length < 2 || (args[1] != "-c" && args[1] != "-u"))
        {
            Console.WriteLine("Input error!");
            return;
        }

        string filePath = args[0];
        string operation = args[1];
        string resultFileName;

        if (!File.Exists(filePath) || (operation == "-u" && Path.GetExtension(filePath) != ".zipped"))
        {
            Console.WriteLine("Invalid input file.");
            return;
        }

        string originalData = File.ReadAllText(filePath);

        if (operation == "-c")
        {
            resultFileName = filePath + ".zipped";
            File.WriteAllLines(resultFileName, LZW.Compress(originalData).Select(c => c.ToString()));
        }
        else
        {
            resultFileName = Path.ChangeExtension(filePath, null);
            File.WriteAllText(resultFileName, LZW.Decompress(File.ReadAllLines(filePath).Select(int.Parse).ToList()));
        }

        Console.WriteLine("Operation completed successfully. Result saved to: " + resultFileName);
    }
}
