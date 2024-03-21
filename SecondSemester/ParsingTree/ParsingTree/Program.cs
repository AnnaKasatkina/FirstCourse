/// <summary>
/// Represents the main program class.
/// </summary>
internal class Program
{
    private static void Main()
    {
        try
        {
            string filePath = "Expression.txt";
            if (!File.Exists(filePath))
            {
                throw new FileNotFoundException("File not found", filePath);
            }

            string expression;
            using (StreamReader sr = new(filePath))
            {
                expression = sr.ReadToEnd();
            }

            ParsingTree? tree = ParsingTree.BuildTree(expression);

            if (tree != null)
            {
                tree.Print();

                int result = tree.Evaluate();
                Console.WriteLine("Result: " + result);
            }
            else
            {
                Console.WriteLine("Error: Unable to build parsing tree");
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine("Error: " + ex.Message);
        }
    }
}
