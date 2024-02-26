public class StackTests
{
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

    private static bool TestCase(string expression, double result)
    {
        var calculatorWithArrayStack = new StackCalculator(new ArrayStack(expression.Split(' ').Length));
        var calculatorWithListStack = new StackCalculator(new ListStack());
        return result == calculatorWithArrayStack.Calculate(expression) &&
            result == calculatorWithListStack.Calculate(expression);
    }

    private static void PrintResult(string name, bool result)
    {
        Console.WriteLine(name + (result ? "was completed successfully" : "ended with an error"));
    }
}
