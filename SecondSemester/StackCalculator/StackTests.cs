/// <summary>
/// Class for testing stack-based calculator functionality.
/// </summary>
public class StackTests
{
    /// <summary>
    /// Runs the test cases for stack-based calculator.
    /// </summary>
    /// <returns>True if all test cases pass, otherwise false.</returns>
    public static bool RunTests()
    {
        bool withNegativeNumbers = TestCase("6 -12 -7 + *", -114);
        PrintResult("with Negative Numbers", withNegativeNumbers);

        bool withZero = TestCase("0 58 2 + *", 0);
        PrintResult("with Zero", withZero);

        bool withSingleNumber = TestCase("121", 121);
        PrintResult("with Single Number", withSingleNumber);

        Console.WriteLine();
        return withNegativeNumbers && withZero && withSingleNumber;
    }

    /// <summary>
    /// Executes a test case for the given expression and expected result.
    /// </summary>
    /// <param name="expression">The expression to evaluate.</param>
    /// <param name="result">The expected result of the expression.</param>
    /// <returns>True if the calculated result matches the expected result, otherwise false.</returns>
    private static bool TestCase(string expression, double result)
    {
        var calculatorWithArrayStack = new StackCalculator(new ArrayStack(expression.Split(' ').Length));
        var calculatorWithListStack = new StackCalculator(new ListStack());
        return result == calculatorWithArrayStack.Calculate(expression) &&
            result == calculatorWithListStack.Calculate(expression);
    }

    /// <summary>
    /// Prints the result of a test case.
    /// </summary>
    /// <param name="name">The name or description of the test case.</param>
    /// <param name="result">The result of the test case (true for success, false for error).</param>
    private static void PrintResult(string name, bool result)
    {
        Console.WriteLine(name + (result ? " was completed successfully" : " ended with an error"));
    }
}
