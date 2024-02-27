public class Trie
{
    private TrieNode root;
    private int size;

    public Trie()
    {
        root = new TrieNode('\0');
        size = 0;
    }

    public bool Add(string element)
    {
        TrieNode currentElement = root;
        Stack<TrieNode> parentStack = new Stack<TrieNode>();

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
            UpdatePrefixCount(parentStack, 1);
            ++size;
            return true;
        }

        return false;
    }

    public bool Contains(string element)
    {
        TrieNode currentElement = root;

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

    public bool Remove(string element)
    {
        TrieNode currentElement = root;
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
        UpdatePrefixCount(parentStack, -1);
        --size;

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

    private void UpdatePrefixCount(Stack<TrieNode> parentStack, int countChange)
    {
        while (parentStack.Count > 0)
        {
            TrieNode parentNode = parentStack.Pop();
            parentNode.WordsWithPrefix += countChange;
        }
    }

    public int HowManyStartsWithPrefix(String prefix)
    {
        TrieNode currentElement = root;

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

    public int Size
    { get { return size; } }

}
