class Program
{
    static void Main()
    {
        if (!BWTTests.RunTests()) 
        { 
            return;
        }

        Console.Write("Enter the input string: ");
        var inputString = Console.ReadLine();
        if (inputString == null) 
        { 
            return;
        }

        var result = BWT.BWTransform(inputString);

        Console.WriteLine("BWT result: " + result.Item1);
        Console.WriteLine("Position: " + result.Item2);

        var originalString = BWT.InverseBWTransform(result.Item1, result.Item2);
        Console.WriteLine("Original String: " + originalString);
    }
}
