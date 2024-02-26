public class StackCalculator
{
    private IStack stack;
    private double epsilon = 1e-10;

    public StackCalculator(IStack stackInstance)
    {
        stack = stackInstance;
    }

    public double Calculate(string expression)
    {
        string[] inputValues = expression.Split(' ');
        foreach (var inputValue in inputValues)
        {
            if (double.TryParse(inputValue, out double operand))
            {
                stack.Push(operand);
            }
            else
            {
                double operand2 = stack.Pop();
                double operand1 = stack.Pop();
                double result = PerformOperation(inputValue, operand1, operand2);
                stack.Push(result);
            }
        }
        return stack.Pop();
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
                if (Math.Abs(operand2) < epsilon)
                {
                    throw new DivideByZeroException("Division by zero");
                }
                return (double)operand1 / operand2;
            default:
                throw new ArgumentException("Invalid operator");
        }
    }
}
