/// <summary>
/// Represents a stack data structure implemented using an array.
/// </summary>
public class ArrayStack : IStack
{
    private double[] array;
    private int top;

    /// <summary>
    /// Initializes a new instance of the <see cref="ArrayStack"/> class with the specified size.
    /// </summary>
    /// <param name="size">The maximum size of the stack.</param>
    public ArrayStack(int size)
    {
        this.array = new double[size];
        this.top = -1;
    }

    /// <inheritdoc/>
    public void Push(double element)
    {
        if (this.top == this.array.Length - 1)
        {
            Array.Resize(ref this.array, this.array.Length * 2);
        }

        this.array[++this.top] = element;
    }

    /// <inheritdoc/>
    public double Pop()
    {
        if (this.IsEmpty())
        {
            throw new InvalidOperationException("Stack is empty!");
        }

        return this.array[this.top--];
    }

    /// <inheritdoc/>
    public bool IsEmpty()
    {
        return this.top == -1;
    }
}
