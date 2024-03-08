/// <summary>
/// Represents a simple stack-based calculator.
/// </summary>
public class StackCalculator
{
    private IStack stack;
    private double epsilon = 1e-10;

    /// <summary>
    /// Initializes a new instance of the <see cref="StackCalculator"/> class with the specified stack implementation.
    /// </summary>
    /// <param name="stackInstance">The stack instance to be used for calculations.</param>
    public StackCalculator(IStack stackInstance)
    {
        this.stack = stackInstance;
    }

    /// <summary>
    /// Performs postfix notation calculation on the provided expression.
    /// </summary>
    /// <param name="expression">The expression in postfix notation.</param>
    /// <returns>The result of the calculation.</returns>
    public double Calculate(string expression)
    {
        string[] inputValues = expression.Split(' ');
        foreach (var inputValue in inputValues)
        {
            if (double.TryParse(inputValue, out double operand))
            {
                this.stack.Push(operand);
            }
            else
            {
                double operand2 = this.stack.Pop();
                double operand1 = this.stack.Pop();
                double result = this.PerformOperation(inputValue, operand1, operand2);
                this.stack.Push(result);
            }
        }

        return this.stack.Pop();
    }

    private double PerformOperation(string operation, double operand1, double operand2)
    {
        switch (operation)
        {
            case "+":
                return operand1 + operand2;
            case "-":
                return operand1 - operand2;
            case "*":
                return operand1 * operand2;
            case "/":
                if (Math.Abs(operand2) < this.epsilon)
                {
                    throw new DivideByZeroException("Division by zero");
                }

                return (double)operand1 / operand2;
            default:
                throw new ArgumentException("Invalid operator");
        }
    }
}
