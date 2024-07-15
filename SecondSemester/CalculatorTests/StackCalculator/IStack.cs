/// <summary>
/// Represents a generic stack interface.
/// </summary>
public interface IStack
{
    /// <summary>
    /// Adds an element to the top of the stack.
    /// </summary>
    /// <param name="element">The element to be added to the stack.</param>
    void Push(double element);

    /// <summary>
    /// Removes and returns the element from the top of the stack.
    /// </summary>
    /// <returns>The element removed from the top of the stack.</returns>
    double Pop();
}
