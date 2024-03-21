/// <summary>
/// Represents a node in a parsing tree.
/// </summary>
public interface INode
{
    /// <summary>
    /// Calculates the value of the node.
    /// </summary>
    /// <returns>The calculated value.</returns>
    int Calculate();

    /// <summary>
    /// Prints the node.
    /// </summary>
    void Print();
}
