/// <summary>
/// Represents a node in the Trie data structure used for LZW compression.
/// </summary>
/// <remarks>
/// Initializes a new instance of the <see cref="TrieNode"/> class with the specified character and code.
/// </remarks>
/// <param name="character">The character value of the node.</param>
/// <param name="code">The code associated with the node.</param>
public class TrieNode(char character, int code)
{
    public char Value = character;
    public int Code = code;
    public List<TrieNode> Children = [];
    public bool IsEndOfWord = false;
    public int WordsWithPrefix = 0;
}
