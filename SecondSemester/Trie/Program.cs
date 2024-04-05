// <copyright file="Program.cs" company="PlaceholderCompany">
// Copyright (c) PlaceholderCompany. All rights reserved.
// </copyright>

/// <summary>
/// Entry point class for the program.
/// </summary>
internal class Program
{
    private static void Main()
    {
        if (!TrieTests.RunTests())
        {
            Console.WriteLine("The tests failed!");
            return;
        }

        TrieUserInterface.Run();
    }
}
