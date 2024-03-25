/// <summary>
/// Represents a list of integers that only allows unique elements.
/// </summary>
public class UniqueList : ListBase
{
    /// <summary>
    /// Adds a unique integer element at the specified position in the list.
    /// </summary>
    /// <param name="element">The integer element to add.</param>
    /// <param name="position">The position at which to add the element.</param>
    /// <exception cref="DuplicateElementException">Thrown when attempting to add an element that already exists in the list.</exception>
    public override void AddElement(int element, int position)
    {
        if (this.Elements.Contains(element))
        {
            throw new DuplicateElementException("Element already exists in the list");
        }

        base.AddElement(element, position);
    }
}
