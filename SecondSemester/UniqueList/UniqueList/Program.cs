// <copyright file="Program.cs" company="PlaceholderCompany">
// Copyright (c) PlaceholderCompany. All rights reserved.
// </copyright>

/// <summary>
/// Represents the main entry point for the program.
/// </summary>
internal class Program
{
    private static void Main()
    {
        try
        {
            UniqueList uniqueList = new();
            uniqueList.AddElement(1, 0);
            uniqueList.AddElement(2, 1);
            uniqueList.AddElement(3, 2);
            uniqueList.AddElement(4, 3);
            uniqueList.AddElement(5, 4);
            uniqueList.AddElement(1, 2); // Попытка добавить уже существующий элемент

            uniqueList.RemoveElement(2);
            uniqueList.ModifyElement(10, 1);
            uniqueList.RemoveElement(6); // Попытка удалить несуществующий элемент
        }
        catch (Exception ex)
        {
            Console.WriteLine("Exception: " + ex.Message);
        }
    }
}
