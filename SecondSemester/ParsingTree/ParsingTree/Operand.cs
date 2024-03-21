/// <summary>
/// Represents an operand node in a parsing tree.
/// </summary>
/// <remarks>
/// Initializes a new instance of the <see cref="Operand"/> class with the specified value.
/// </remarks>
/// <param name="value">The value of the operand.</param>
public class Operand(int value) : INode
{
    private readonly int value = value;

    /// <summary>
    /// Retrieves the value of the operand.
    /// </summary>
    /// <returns>The value of the operand.</returns>
    public int Calculate()
    {
        return this.value;
    }

    /// <summary>
    /// Prints the value of the operand.
    /// </summary>
    public void Print()
    {
        Console.Write(this.value);
    }
}
