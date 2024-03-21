/// <summary>
/// The main program class for the StackCalculator application.
/// </summary>
internal class Program
{
    private static void Main()
    {
        if (!StackTests.RunTests())
        {
            return;
        }

        Console.WriteLine("Enter the expression in postfix notation:");
        var expression = Console.ReadLine();
        if (expression == null)
        {
            Console.WriteLine("Error: The input expression is null!");
            return;
        }

        try
        {
            var calculatorWithArrayStack = new StackCalculator(new ArrayStack(expression.Split(' ').Length));
            double resultWithArrayStack = calculatorWithArrayStack.Calculate(expression);
            Console.WriteLine("Result with array stack: " + resultWithArrayStack);

            var calculatorWithListStack = new StackCalculator(new ListStack());
            double resultWithListStack = calculatorWithListStack.Calculate(expression);
            Console.WriteLine("Result with list stack: " + resultWithListStack);
        }
        catch (Exception ex)
        {
            Console.WriteLine("Error: " + ex.Message);
        }
    }
}
