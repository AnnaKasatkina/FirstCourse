public class TrieTests
{ 
    public static bool RunTests()
    {
        Trie trie = new();

        bool result = TestOne(trie);
        result &= TestTwo(trie);
        result &= TestThree(trie);
        result &= TestFour(trie);
        result &= TestFive(trie);
        result &= TestSix(trie);

        Console.WriteLine();
        return result;
    }

    private static bool TestOne(Trie trie)
    {
        trie.Add("apple");
        bool result = trie.Size == 1;
        PrintResult("Adding elements and increasing size", result);

        return result;
    }

    private static bool TestTwo(Trie trie)
    {
        trie.Add("apple");
        bool result = trie.Size == 1;
        PrintResult("Adding a duplicate and no increase in size", result);

        return result;
    }

    private static bool TestThree(Trie trie)
    {
        bool result = trie.Contains("apple");
        result &= !trie.Contains("orange");
        PrintResult("Checking the presence of an element", result);

        return result;
    }

    private static bool TestFour(Trie trie)
    {
        trie.Remove("orange");
        bool result = trie.Size == 1;
        PrintResult("Removing a non-existent element and no decrease in size", result);

        return result;
    }

    private static bool TestFive(Trie trie)
    {
        trie.Remove("apple");
        bool result = trie.Size == 0;
        PrintResult("Removing an element and decreasing size", result);

        return result;
    }

    private static bool TestSix(Trie trie)
    {
        trie.Add("app");
        trie.Add("apricot");
        bool result = trie.HowManyStartsWithPrefix("ap") == 2;
        PrintResult("Counting elements with a prefix", result);

        return result;
    }

    private static void PrintResult(string name, bool result)
    {
        Console.WriteLine("Test " + name + (result ? "was completed successfully" : "ended with an error"));
    }
}
