/// <summary>
/// Represents a trie data structure, which is a tree-like data structure used to store a dynamic set of strings.
/// </summary>
public class Trie
{
    private class TrieNode(char character)
    {
        public char Value = character;
        public bool IsEndOfWord = false;
        public List<TrieNode> Children = [];
        public int WordsWithPrefix = 0;
    }

    private readonly TrieNode root;
    private int size;

    /// <summary>
    /// Initializes a new instance of the <see cref="Trie"/> class.
    /// </summary>
    public Trie()
    {
        this.root = new TrieNode('\0');
        this.size = 0;
    }

    /// <summary>
    /// Adds a string element to the trie.
    /// </summary>
    /// <param name="element">The string element to add.</param>
    /// <returns>True if the element was added successfully, otherwise false.</returns>
    public bool Add(string element)
    {
        TrieNode currentElement = this.root;
        var parentStack = new Stack<TrieNode>();

        foreach (char character in element)
        {
            TrieNode? childElement = currentElement.Children.Find(node => node.Value == character);
            if (childElement == null)
            {
                childElement = new TrieNode(character);
                currentElement.Children.Add(childElement);
            }

            parentStack.Push(currentElement);
            currentElement = childElement;
        }

        if (!currentElement.IsEndOfWord)
        {
            currentElement.IsEndOfWord = true;
            this.UpdatePrefixCount(parentStack, 1);
            ++this.size;
            return true;
        }

        return false;
    }

    /// <summary>
    /// Determines whether the trie contains a specific string element.
    /// </summary>
    /// <param name="element">The string element to locate.</param>
    /// <returns>True if the trie contains the element, otherwise false.</returns>
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
    /// Removes a specific string element from the trie.
    /// </summary>
    /// <param name="element">The string element to remove.</param>
    /// <returns>True if the element was successfully removed, otherwise false.</returns>
    public bool Remove(string element)
    {
        TrieNode currentElement = this.root;
        var parentStack = new Stack<TrieNode>();

        foreach (char character in element)
        {
            TrieNode? childElement = currentElement.Children.Find(node => node.Value == character);
            if (childElement == null)
            {
                return false;
            }

            parentStack.Push(currentElement);
            currentElement = childElement;
        }

        if (!currentElement.IsEndOfWord)
        {
            return false;
        }

        currentElement.IsEndOfWord = false;
        this.UpdatePrefixCount(parentStack, -1);
        --this.size;

        if (currentElement.Children.Count != 0)
        {
            return true;
        }

        while (parentStack.Count > 0)
        {
            TrieNode parentNode = parentStack.Pop();
            parentNode.Children.RemoveAll(node => node.Value == element[^1]);
            if (parentNode.Children.Count > 0 || parentNode.IsEndOfWord)
            {
                break;
            }
        }

        return true;
    }

    /// <summary>
    /// Gets returns the number of elements in the trie.
    /// </summary>
    public int Size
    {
        get { return this.size; }
    }

    /// <summary>
    /// Returns the number of elements with the specified prefix.
    /// </summary>
    /// <param name="prefix">The prefix to search for.</param>
    /// <returns>The number of elements with the specified prefix.</returns>
    public int HowManyStartsWithPrefix(string prefix)
    {
        TrieNode currentElement = this.root;

        foreach (char character in prefix)
        {
            TrieNode? childElement = currentElement.Children.Find(node => node.Value == character);
            if (childElement == null)
            {
                return 0;
            }

            currentElement = childElement;
        }

        return currentElement.WordsWithPrefix;
    }

    private void UpdatePrefixCount(Stack<TrieNode> parentStack, int countChange)
    {
        while (parentStack.Count > 0)
        {
            TrieNode parentNode = parentStack.Pop();
            parentNode.WordsWithPrefix += countChange;
        }
    }
}
