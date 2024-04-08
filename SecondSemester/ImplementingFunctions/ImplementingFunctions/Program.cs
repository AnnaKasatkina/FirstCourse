// <copyright file="Program.cs" company="PlaceholderCompany">
// Copyright (c) PlaceholderCompany. All rights reserved.
// </copyright>

namespace ImplementingFunctions
{
    /// <summary>
    /// Represents the main program class.
    /// </summary>
    internal class Program
    {
        private static void Main(string[] args)
        {
            var numbers = new List<int>() { 1, 2, 3 };
            var doubledNumbers = ImplementingFunctions.Map(numbers, x => x * 2);
            Console.WriteLine(string.Join(", ", doubledNumbers));

            var mixedList = new List<object> { 1, "apple", 'a', 3.14, true, "banana" };
            var filteredNumbersAndStrings = ImplementingFunctions.Filter(mixedList, x => x is int || x is string);
            Console.WriteLine(string.Join("; ", filteredNumbersAndStrings));

            var result = ImplementingFunctions.Fold(new List<int>() { 1, 2, 3 }, 1, (acc, elem) => acc * elem);
            Console.WriteLine(result);
        }
    }
}