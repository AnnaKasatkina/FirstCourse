class Program
{
    static void Main()
    {
        if (!TrieTests.RunTests())
        {
            return;
        }

        TrieUserInterface.Run();
    }
}
