/// <summary>
/// Represents a stack data structure implemented using a list.
/// </summary>
public class ListStack : IStack
{
    private List<double> list;

    /// <summary>
    /// Initializes a new instance of the <see cref="ListStack"/> class.
    /// </summary>
    public ListStack()
    {
        this.list = [];
    }

    /// <summary>
    /// Adds an element to the top of the stack.
    /// </summary>
    /// <param name="element">The element to be added to the stack.</param>
    public void Push(double element)
    {
        this.list.Add(element);
    }

    /// <summary>
    /// Removes and returns the element from the top of the stack.
    /// </summary>
    /// <returns>The element removed from the top of the stack.</returns>
    public double Pop()
    {
        if (this.list.Count == 0)
        {
            throw new InvalidOperationException("Stack is empty");
        }

        double element = this.list[^1];
        this.list.RemoveAt(this.list.Count - 1);
        return element;
    }
}
