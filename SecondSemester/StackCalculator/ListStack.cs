public class ListStack : IStack
{
    private List<double> list;

    public ListStack()
    {
        list = new List<double>();
    }

    public void Push(double element)
    {
        list.Add(element);
    }

    public double Pop()
    {
        if (list.Count == 0)
        {
            throw new InvalidOperationException("Stack is empty");
        }
        double element = list[^1];
        list.RemoveAt(list.Count - 1);
        return element;
    }
}
