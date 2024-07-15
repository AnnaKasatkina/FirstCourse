// <copyright file="FoldTests.cs" company="PlaceholderCompany">
// Copyright (c) PlaceholderCompany. All rights reserved.
// </copyright>

namespace ImplementingFunctionsTests
{
    /// <summary>
    /// Unit tests for the Fold function.
    /// </summary>
    public class FoldTests
    {
        private static readonly object[] TestData =
        {
            new object[]
            {
                new List<int> { 1, 2, 3, 4, 5 }, string.Empty,
                new Func<string, int, string>((acc, x) => acc + x.ToString()), "12345",
            },

            new object[]
            {
                new List<string> { "This", "is", "a", "test" }, string.Empty,
                new Func<string, string, string>((acc, x) => acc + x + " "), "This is a test ",
            },

            new object[]
            {
                new List<int> { 3, 7, 2, 9, 5 },  int.MinValue,
                new Func<int, int, int>((acc, x) => Math.Max(acc, x)), 9,
            },

            new object[]
            {
                new List<List<int>> { new List<int> { 1, 2 }, new List<int> { 3, 4 }, new List<int> { 5, 6 } },
                new List<int>(), new Func<List<int>, List<int>, List<int>>((acc, x) =>
                {
                    acc.AddRange(x);
                    return acc;
                }), new List<int> { 1, 2, 3, 4, 5, 6 },
            },
        };

        /// <summary>
        /// Test case for Fold method.
        /// </summary>
        /// <typeparam name="TResult">Type of result.</typeparam>
        /// <typeparam name="T">Type of list elements.</typeparam>
        /// <param name="list">List to fold.</param>
        /// <param name="initialValue">Initial value.</param>
        /// <param name="func">Function to apply during fold.</param>
        /// <param name="expectedResult">Expected result.</param>
        [Test]
        [TestCaseSource(nameof(TestData))]
        public void FoldTestCaseFold<TResult, T>(List<T> list, TResult initialValue, Func<TResult, T, TResult> func, TResult expectedResult)
        {
            var result = ImplementingFunctions.ImplementingFunctions.Fold(list, initialValue, func);
            Assert.That(result, Is.EqualTo(expectedResult));
        }
    }
}
