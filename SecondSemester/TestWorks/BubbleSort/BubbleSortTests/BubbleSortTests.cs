// <copyright file="BubbleSortTests.cs" company="Kasatkina Anna">
// Copyright (c) Kasatkina Anna. All rights reserved.
// </copyright>

namespace BubbleSortTests
{
    /// <summary>
    /// Unit tests for the bubble sorting method.
    /// </summary>
    public class BubbleSortTests
    {
        /// <summary>
        /// Test data for sorting integer lists.
        /// </summary>
        private static readonly object[] IntTestData =
        {
            new object[]
            {
                new List<int> { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 },
                new List<int> { 1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9 },
                new IntComparer(),
            },
            new object[]
            {
                new List<int>(),
                new List<int>(),
                new IntComparer(),
            },
            new object[]
            {
                new List<int> { 42 },
                new List<int> { 42 },
                new IntComparer(),
            },
            new object[]
            {
                new List<int> { -3, -1, -4, -1, -5, -9, -2, -6, -5, -3, -5 },
                new List<int> { -9, -6, -5, -5, -5, -4, -3, -3, -2, -1, -1 },
                new IntComparer(),
            },
            new object[]
            {
                new List<int> { 5, 5, 5, 5, 5 },
                new List<int> { 5, 5, 5, 5, 5 },
                new IntComparer(),
            },
        };

        /// <summary>
        /// Test data for sorting string lists.
        /// </summary>
        private static readonly object[] StringTestData =
        {
            new object[]
            {
                new List<string> { "apple", "orange", "banana", "grape", "pear" },
                new List<string> { "apple", "banana", "grape", "orange", "pear" },
                new StringComparer(),
            },
            new object[]
            {
                new List<string> { "apple", "banana", "banana", "apple" },
                new List<string> { "apple", "apple", "banana", "banana" },
                new StringComparer(),
            },
            new object[]
            {
                new List<string> { "C", "B", "d", "a", "e" },
                new List<string> { "a", "B", "C", "d", "e" },
                new StringComparer(),
            },
        };

        /// <summary>
        /// Tests sorting of a list of integers.
        /// </summary>
        /// <param name="list">The list of integers to be sorted.</param>
        /// <param name="expected">The expected sorted list.</param>
        /// <param name="comparer">The comparer to use for sorting.</param>
        [Test]
        [TestCaseSource(nameof(IntTestData))]
        public void IntListTest(List<int> list, List<int> expected, IComparer<int> comparer)
        {
            BubbleSort.BubbleSort.Sort(list, comparer);
            Assert.That(list, Is.EqualTo(expected));
        }

        /// <summary>
        /// Tests sorting of a list of strings.
        /// </summary>
        /// <param name="list">The list of strings to be sorted.</param>
        /// <param name="expected">The expected sorted list.</param>
        /// <param name="comparer">The comparer to use for sorting.</param>
        [Test]
        [TestCaseSource(nameof(StringTestData))]
        public void StringListTest(List<string> list, List<string> expected, IComparer<string> comparer)
        {
            BubbleSort.BubbleSort.Sort(list, comparer);
            Assert.That(list, Is.EqualTo(expected));
        }

        /// <summary>
        /// Tests handling of a null list argument.
        /// </summary>
        [Test]
        public void NullListTest()
        {
            Assert.Throws<ArgumentNullException>(() => BubbleSort.BubbleSort.Sort<int>(null, new IntComparer()));
        }

        /// <summary>
        /// Tests handling of a null comparer argument.
        /// </summary>
        [Test]
        public void NullComparerTest()
        {
            var list = new List<int> { 1, 2, 3 };
            Assert.Throws<ArgumentNullException>(() => BubbleSort.BubbleSort.Sort(list, null));
        }

        private class IntComparer : IComparer<int>
        {
            public int Compare(int x, int y)
            {
                return x.CompareTo(y);
            }
        }

        private class StringComparer : IComparer<string>
        {
            public int Compare(string? x, string? y)
            {
                return string.Compare(x, y);
            }
        }
    }
}
