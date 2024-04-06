// <copyright file="ListBase.cs" company="PlaceholderCompany">
// Copyright (c) PlaceholderCompany. All rights reserved.
// </copyright>

/// <summary>
/// Represents a base class for managing a list of integers.
/// </summary>
public class ListBase
{
    /// <summary>
    /// The list of integers.
    /// </summary>
    public List<int> Elements;

    /// <summary>
    /// Initializes a new instance of the <see cref="ListBase"/> class.
    /// </summary>
    public ListBase()
    {
        this.Elements = [];
    }

    /// <summary>
    /// Adds an integer element at the specified position in the list.
    /// </summary>
    /// <param name="element">The integer element to add.</param>
    /// <param name="position">The position at which to add the element.</param>
    public virtual void AddElement(int element, int position)
    {
        this.Elements.Insert(position, element);
    }

    /// <summary>
    /// Removes the integer element at the specified position from the list.
    /// </summary>
    /// <param name="position">The position of the element to remove.</param>
    /// <exception cref="ElementNotFoundException">Thrown when the specified position is out of range.</exception>
    public virtual void RemoveElement(int position)
    {
        if (position < 0 || position >= this.Elements.Count)
        {
            throw new ElementNotFoundException("Element not found at position " + position);
        }

        this.Elements.RemoveAt(position);
    }

    /// <summary>
    /// Modifies the integer element at the specified position in the list.
    /// </summary>
    /// <param name="element">The new value for the element.</param>
    /// <param name="position">The position of the element to modify.</param>
    /// <exception cref="ElementNotFoundException">Thrown when the specified position is out of range.</exception>
    public virtual void ModifyElement(int element, int position)
    {
        if (position < 0 || position >= this.Elements.Count)
        {
            throw new ElementNotFoundException("Element not found at position " + position);
        }

        this.Elements[position] = element;
    }
}
