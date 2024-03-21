public class UniqueList : ListBase
{
    public override void AddElement(int element, int position)
    {
        if (elements.Contains(element))
            throw new DuplicateElementException("Element already exists in the list");

        base.AddElement(element, position);
    }
}
