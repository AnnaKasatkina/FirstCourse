/// <summary>
/// Entry point class for the program.
/// </summary>
internal class Program
{
    private static void Main()
    {
        if (!TrieTests.RunTests())
        {
            return;
        }

        TrieUserInterface.Run();
    }
}
