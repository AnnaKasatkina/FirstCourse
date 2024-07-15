/// <summary>
/// Provides a user interface to interact with a Trie data structure.
/// </summary>
public class TrieUserInterface
{
    private static Trie trie = new();

    /// <summary>
    /// Runs the user interface for interacting with the Trie.
    /// </summary>
    public static void Run()
    {
        while (true)
        {
            Console.WriteLine("\nOptions:");
            Console.WriteLine("1. Add Element");
            Console.WriteLine("2. Check if Element Exists");
            Console.WriteLine("3. Remove Element");
            Console.WriteLine("4. Count Elements with Prefix");
            Console.WriteLine("5. Display Trie Size");
            Console.WriteLine("6. Exit");

            Console.Write("Enter your choice (1-6): ");
            string? choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                    AddElement();
                    break;

                case "2":
                    CheckElementExists();
                    break;

                case "3":
                    RemoveElement();
                    break;

                case "4":
                    CountWithPrefix();
                    break;

                case "5":
                    DisplayTrieSize();
                    break;

                case "6":
                    Console.WriteLine("Exiting program. Goodbye!");
                    return;

                default:
                    Console.WriteLine("Invalid choice. Please enter a number between 1 and 6.");
                    break;
            }
        }
    }

    private static void AddElement()
    {
        Console.Write("Enter element to add: ");
        string? addElement = Console.ReadLine();
        if (addElement == null)
        {
            Console.WriteLine("Error input!");
            return;
        }

        if (trie.Add(addElement))
        {
            Console.WriteLine($"Element '{addElement}' added to Trie.");
        }
        else
        {
            Console.WriteLine($"Element '{addElement}' already exists in Trie.");
        }
    }

    private static void CheckElementExists()
    {
        Console.Write("Enter element to check: ");
        string? checkElement = Console.ReadLine();
        if (checkElement == null)
        {
            Console.WriteLine("Error input!");
            return;
        }

        if (trie.Contains(checkElement))
        {
            Console.WriteLine($"Element '{checkElement}' exists in Trie.");
        }
        else
        {
            Console.WriteLine($"Element '{checkElement}' does not exist in Trie.");
        }
    }

    private static void RemoveElement()
    {
        Console.Write("Enter element to remove: ");
        string? removeElement = Console.ReadLine();
        if (removeElement == null)
        {
            Console.WriteLine("Error input!");
            return;
        }

        if (trie.Remove(removeElement))
        {
            Console.WriteLine($"Element '{removeElement}' removed from Trie.");
        }
        else
        {
            Console.WriteLine($"Element '{removeElement}' does not exist in Trie.");
        }
    }

    private static void CountWithPrefix()
    {
        Console.Write("Enter prefix to count: ");
        string? prefix = Console.ReadLine();
        if (prefix == null)
        {
            Console.WriteLine("Error input!");
            return;
        }

        int count = trie.HowManyStartsWithPrefix(prefix);
        Console.WriteLine($"Number of elements with prefix '{prefix}': {count}");
    }

    private static void DisplayTrieSize()
    {
        Console.WriteLine($"Trie Size: {trie.Size}");
    }
}
