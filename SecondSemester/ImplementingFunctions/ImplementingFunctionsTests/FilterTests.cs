// <copyright file="FilterTests.cs" company="PlaceholderCompany">
// Copyright (c) PlaceholderCompany. All rights reserved.
// </copyright>

namespace ImplementingFunctionsTests
{
    /// <summary>
    /// Unit tests for the Filter function.
    /// </summary>
    public class FilterTests
    {
        private static readonly object[] TestData =
        {
            new object[]
            {
                new List<int> { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, new Func<int, bool>(x => x % 2 == 0),
                new List<int> { 2, 4, 6, 8 },
            },

            new object[]
            {
                new List<string> { "apple", "banana", "orange", "grape" }, new Func<string, bool>(x => x.Length > 5),
                new List<string> { "banana", "orange" },
            },

            new object[]
            {
                new List<int> { 1, 2, 3, 4, 5 }, new Func<int, bool>(x => x > 10),
                new List<int> { },
            },

            new object[]
            {
                new List<int> { 1, 2, 3, 4, 5 }, new Func<int, bool>(x => true),
                new List<int> { 1, 2, 3, 4, 5 },
            },

            new object[]
            {
                new List<object> { 1, "apple", 'a', 3.14, true }, new Func<object, bool>(x => x is int || x is string),
                new List<object> { 1, "apple" },
            },
        };

        /// <summary>
        /// Tests the Map function with various input scenarios.
        /// </summary>
        /// <typeparam name="T">The type of elements in the list.</typeparam>
        /// <param name="list">The input list to be filtered.</param>
        /// <param name="func">The filtering function that filter each element of the input list.</param>
        /// <param name="expectedResult">Expected result after filtering.</param>
        [Test]
        [TestCaseSource(nameof(TestData))]
        public void FilterTestCase<T>(List<T> list, Func<T, bool> func, List<T> expectedResult)
        {
            var result = ImplementingFunctions.ImplementingFunctions.Filter(list, func);
            Assert.That(result, Is.EqualTo(expectedResult));
        }
    }
}
