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

    /// <summary>
    /// Adds an element to the top of the stack.
    /// </summary>
    /// <param name="element">The element to be added to the stack.</param>
    public void Push(double element)
    {
        if (this.top == this.array.Length - 1)
        {
            throw new StackOverflowException("Stack overflow");
        }

        this.array[++this.top] = element;
    }

    /// <summary>
    /// Removes and returns the element from the top of the stack.
    /// </summary>
    /// <returns>The element removed from the top of the stack.</returns>
    public double Pop()
    {
        if (this.top == -1)
        {
            throw new InvalidOperationException("Stack is empty!");
        }

        return this.array[this.top--];
    }
}
