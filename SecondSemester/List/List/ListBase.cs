public class ListBase
{
    protected List<int> elements;

    public ListBase()
    {
        elements = new List<int>();
    }

    public virtual void AddElement(int element, int position)
    {
        elements.Insert(position, element);
    }

    public virtual void RemoveElement(int position)
    {
        if (position < 0 || position >= elements.Count)
            throw new ElementNotFoundException("Element not found at position " + position);

        elements.RemoveAt(position);
    }

    public virtual void ModifyElement(int element, int position)
    {
        if (position < 0 || position >= elements.Count)
            throw new ElementNotFoundException("Element not found at position " + position);

        elements[position] = element;
    }
}
