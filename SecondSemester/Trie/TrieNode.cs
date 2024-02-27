public class TrieNode(char character)
{
    public char Value = character;
    public bool IsEndOfWord = false;
    public List<TrieNode> Children = [];
    public int WordsWithPrefix = 0;
}
