namespace SkipList;

public class SkipList<T>:
{
    private class Node
    {
        public T Value { get; set; }
        public Node[] Next { get; set; }

        public Node(int level)
        {
            Next = new Node[level + 1];
        }
    }
}