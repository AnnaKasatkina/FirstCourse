public class BWTTests
{
    public static bool RunTests()
    {
        bool withLongWord = TestCase("pneumonoultramicroscopic", "rsiinpmuaupomcrnoctcoloe", 17);
        PrintResult("withLongWord", withLongWord);

        bool withSentence = TestCase("a test for a sentence", "rtaa enctst eefo esn ", 5);
        PrintResult("withSentence", withSentence);

        bool withSingleCharacter = TestCase("b", "b", 0);
        PrintResult("withSingleCharacter", withSingleCharacter);

        Console.WriteLine();
        return withLongWord && withSentence && withSingleCharacter;
    }

    private static bool TestCase(string inputString, string BWTstring, int BWTposition)
    {
        var result = BWT.BWTransform(inputString);
        bool transformResult = BWTstring == result.Item1 && BWTposition == result.Item2;

        var originalString = BWT.InverseBWTransform(result.Item1, result.Item2);
        return transformResult && originalString == inputString;
    }

    private static void PrintResult(string name, bool result)
    {
        Console.WriteLine(name + (result ? "was completed successfully" : "ended with an error"));
    }
}
