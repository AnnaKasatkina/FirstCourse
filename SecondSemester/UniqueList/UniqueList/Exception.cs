// <copyright file="Exception.cs" company="PlaceholderCompany">
// Copyright (c) PlaceholderCompany. All rights reserved.
// </copyright>

/// <summary>
/// Represents an exception that is thrown when attempting to add a duplicate element to a list.
/// </summary>
/// <remarks>
/// Initializes a new instance of the <see cref="DuplicateElementException"/> class with a specified error message.
/// </remarks>
/// <param name="message">The message that describes the error.</param>
public class DuplicateElementException(string message)
    : Exception(message)
{
}

/// <summary>
/// Represents an exception that is thrown when an element is not found in a list.
/// </summary>
public class ElementNotFoundException : Exception
{
    /// <summary>
    /// Initializes a new instance of the <see cref="ElementNotFoundException"/> class with a specified error message.
    /// </summary>
    /// <param name="message">The message that describes the error.</param>
    public ElementNotFoundException(string message)
        : base(message)
    {
    }
}
