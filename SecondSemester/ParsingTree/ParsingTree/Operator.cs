/// <summary>
/// Represents an operator node in a parsing tree.
/// </summary>
/// <remarks>
/// Initializes a new instance of the <see cref="Operator"/> class with the specified operation and operands.
/// </remarks>
/// <param name="operation">The operation symbol.</param>
/// <param name="left">The left operand.</param>
/// <param name="right">The right operand.</param>
public class Operator(char operation, INode left, INode right) : INode
{
    private readonly char operation = operation;
    private readonly INode left = left;
    private readonly INode right = right;

    /// <summary>
    /// Calculates the result of the operation performed on the left and right operands.
    /// </summary>
    /// <returns>The result of the operation.</returns>
    public int Calculate()
    {
        int leftValue = this.left.Calculate();
        int rightValue = this.right.Calculate();

        switch (this.operation)
        {
            case '+':
                return leftValue + rightValue;
            case '-':
                return leftValue - rightValue;
            case '*':
                return leftValue * rightValue;
            case '/':
                if (rightValue == 0)
                {
                    throw new DivideByZeroException("Division by zero");
                }

                return leftValue / rightValue;
            default:
                throw new ArgumentException("Unknown operator");
        }
    }

    /// <summary>
    /// Prints the operator and its operands.
    /// </summary>
    public void Print()
    {
        Console.Write("(");
        this.left.Print();
        Console.Write(" {0} ", this.operation);
        this.right.Print();
        Console.Write(")");
    }
}
