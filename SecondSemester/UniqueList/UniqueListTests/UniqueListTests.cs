using NUnit.Framework;

/// <summary>
/// Represents a set of unit tests for the UniqueList class.
/// </summary>
[TestFixture]
public class UniqueListTests
{
    /// <summary>
    /// Verifies that adding an element to the UniqueList throws an exception when the element already exists.
    /// </summary>
    [Test]
    public void AddElement_ThrowsExceptionWhenElementAlreadyExists()
    {
        UniqueList uniqueList = new();
        uniqueList.AddElement(1, 0);
        Assert.Throws<DuplicateElementException>(() => uniqueList.AddElement(1, 0));
    }

    /// <summary>
    /// Verifies that adding unique elements to the UniqueList increases its count.
    /// </summary>
    [Test]
    public void AddElement_AddsUniqueElementToList()
    {
        UniqueList uniqueList = new();
        uniqueList.AddElement(1, 0);
        uniqueList.AddElement(2, 1);
        uniqueList.AddElement(3, 2);
        Assert.That(uniqueList.elements, Has.Count.EqualTo(3));
    }

    /// <summary>
    /// Verifies that adding an element at a specified position in the UniqueList results in the element being at that position.
    /// </summary>
    [Test]
    public void AddElement_AddsElementAtSpecifiedPosition()
    {
        UniqueList uniqueList = new();
        uniqueList.AddElement(1, 0);
        uniqueList.AddElement(2, 0);
        Assert.That(uniqueList.elements[0], Is.EqualTo(2));
    }

    /// <summary>
    /// Verifies that removing an element from the UniqueList results in an empty list.
    /// </summary>
    [Test]
    public void RemoveElement_RemovesElementFromList()
    {
        UniqueList uniqueList = new();
        uniqueList.AddElement(1, 0);
        uniqueList.RemoveElement(0);
        Assert.That(uniqueList.elements, Is.Empty);
    }

    /// <summary>
    /// Verifies that removing an element from an empty list in the UniqueList throws an exception.
    /// </summary>
    [Test]
    public void RemoveElement_ThrowsExceptionWhenPositionInvalid()
    {
        UniqueList uniqueList = new();
        Assert.Throws<ElementNotFoundException>(() => uniqueList.RemoveElement(0));
    }

    /// <summary>
    /// Verifies that modifying an element in the UniqueList results in the element being modified.
    /// </summary>
    [Test]
    public void ModifyElement_ModifiesElementInList()
    {
        UniqueList uniqueList = new();
        uniqueList.AddElement(1, 0);
        uniqueList.ModifyElement(10, 0);
        Assert.That(uniqueList.elements[0], Is.EqualTo(10));
    }

    /// <summary>
    /// Verifies that modifying an element in an empty list in the UniqueList throws an exception.
    /// </summary>
    [Test]
    public void ModifyElement_ThrowsExceptionWhenPositionInvalid()
    {
        UniqueList uniqueList = new();
        Assert.Throws<ElementNotFoundException>(() => uniqueList.ModifyElement(10, 0));
    }
}
