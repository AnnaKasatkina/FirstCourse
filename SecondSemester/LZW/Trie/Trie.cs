/// <summary>
/// Represents a Trie data structure used for LZW compression.
/// </summary>
public class Trie
{
    /// <summary>
    /// The root node of the Trie.
    /// </summary>
    private readonly TrieNode root;

    /// <summary>
    /// Initializes a new instance of the <see cref="Trie"/> class.
    /// </summary>
    public Trie()
    {
        this.root = new TrieNode('\0', 0);
    }

    /// <summary>
    /// Adds a new element with the specified code to the Trie.
    /// </summary>
    /// <param name="element">The element to be added to the Trie.</param>
    /// <param name="code">The code associated with the element.</param>
    /// <returns>True if the element is added successfully, false if it already exists.</returns>
    public bool Add(string element, int code)
    {
        TrieNode currentElement = this.root;
        Stack<TrieNode> parentStack = new();

        foreach (char character in element)
        {
            TrieNode? childElement = currentElement.Children.Find(node => node.Value == character);
            if (childElement == null)
            {
                childElement = new TrieNode(character, code);
                currentElement.Children.Add(childElement);
            }

            parentStack.Push(currentElement);
            currentElement = childElement;
        }

        if (!currentElement.IsEndOfWord)
        {
            currentElement.IsEndOfWord = true;
            UpdatePrefixCount(parentStack, 1);
            return true;
        }

        return false;
    }

    /// <summary>
    /// Checks if the Trie contains the specified element.
    /// </summary>
    /// <param name="element">The element to check for existence in the Trie.</param>
    /// <returns>True if the element is found, false otherwise.</returns>
    public bool Contains(string element)
    {
        TrieNode currentElement = this.root;

        foreach (char character in element)
        {
            TrieNode? childElement = currentElement.Children.Find(node => node.Value == character);
            if (childElement == null)
            {
                return false;
            }

            currentElement = childElement;
        }

        return currentElement.IsEndOfWord;
    }

    /// <summary>
    /// Gets the code associated with the specified entry.
    /// </summary>
    /// <param name="entry">The entry for which to retrieve the code.</param>
    /// <returns>The code associated with the specified entry.</returns>
    public int GetCodeForEntry(string entry)
    {
        TrieNode currentElement = this.root;

        foreach (char character in entry)
        {
            TrieNode? childElement = currentElement.Children.Find(node => node.Value == character);
            if (childElement == null)
            {
                // If the character is not in the Trie, add a new node with an incremented code
                TrieNode newNode = new(character, currentElement.Code++);
                currentElement.Children.Add(newNode);
                return newNode.Code;
            }

            currentElement = childElement;
        }

        return currentElement.Code;
    }

    /// <summary>
    /// Recursive helper method to get the entry associated with the specified code.
    /// </summary>
    private static string? GetEntryForCodeRecursive(TrieNode node, int code, string currentPrefix)
    {
        if (node.Code == code)
        {
            return currentPrefix + node.Value;
        }

        foreach (var childNode in node.Children)
        {
            string? result = GetEntryForCodeRecursive(childNode, code, currentPrefix + node.Value);
            if (result != null)
            {
                return result;
            }
        }

        return null;
    }

    /// <summary>
    /// Updates the prefix count for the Trie nodes in the specified stack.
    /// </summary>
    private static void UpdatePrefixCount(Stack<TrieNode> parentStack, int countChange)
    {
        while (parentStack.Count > 0)
        {
            TrieNode parentNode = parentStack.Pop();
            parentNode.WordsWithPrefix += countChange;
        }
    }
}
