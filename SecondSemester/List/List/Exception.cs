using System;

public class DuplicateElementException : Exception
{
    public DuplicateElementException(string message) : base(message)
    {
    }
}

public class ElementNotFoundException : Exception
{
    public ElementNotFoundException(string message) : base(message)
    {
    }
}
