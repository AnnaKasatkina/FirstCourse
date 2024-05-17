// <copyright file="BubbleSort.cs" company="Kasatkina Anna">
// Copyright (c) Kasatkina Anna. All rights reserved.
// </copyright>

namespace BubbleSort
{
    /// <summary>
    /// Provides a method for sorting a list of elements using the bubble sort algorithm.
    /// </summary>
    public class BubbleSort
    {
        /// <summary>
        /// Sort the list of items using the bubble sorting method.
        /// </summary>
        /// <typeparam name="T">The type of list elements.</typeparam>
        /// <param name="list">A list of elements to sort.</param>
        /// <param name="comparer">An object implementing the IComparer interface for comparing elements.</param>
        public static void Sort<T>(List<T> list, IComparer<T> comparer)
        {
            ArgumentNullException.ThrowIfNull(list);
            ArgumentNullException.ThrowIfNull(comparer);

            var count = list.Count;
            for (var i = 0; i < count - 1; i++)
            {
                for (var j = 0; j < count - 1 - i; j++)
                {
                    if (comparer.Compare(list[j], list[j + 1]) > 0)
                    {
                        (list[j + 1], list[j]) = (list[j], list[j + 1]);
                    }
                }
            }
        }
    }
}
