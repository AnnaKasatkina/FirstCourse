/// <summary>
/// Represents a stack data structure implemented using a list
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

    /// <inheritdoc/>
    public void Push(double element)
    {
        this.list.Add(element);
    }

    /// <inheritdoc/>
    public double Pop()
    {
        if (this.IsEmpty())
        {
            throw new InvalidOperationException("Stack is empty");
        }

        double element = this.list[^1];
        this.list.RemoveAt(this.list.Count - 1);
        return element;
    }

    /// <inheritdoc/>
    public bool IsEmpty()
    {
        return this.list.Count == 0;
    }
}
