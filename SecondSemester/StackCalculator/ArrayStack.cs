public class ArrayStack : IStack
{
    private double[] array;
    private int top;

    public ArrayStack(int size)
    {
        array = new double[size];
        top = -1;
    }

    public void Push(double element)
    {
        if (top == array.Length - 1)
        {
            throw new StackOverflowException("Stack overflow");
        }
        array[++top] = element;
    }

    public double Pop()
    {
        if (top == -1)
        {
            throw new InvalidOperationException("Stack is empty!");
        }
        return array[top--];
    }
}
