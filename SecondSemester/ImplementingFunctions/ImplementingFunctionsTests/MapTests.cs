// <copyright file="MapTests.cs" company="PlaceholderCompany">
// Copyright (c) PlaceholderCompany. All rights reserved.
// </copyright>

namespace ImplementingFunctionsTests
{
    /// <summary>
    /// Unit tests for the Map function.
    /// </summary>
    public class MapTests
    {
        private static readonly object[] TestData =
        {
            new object[]
            {
                new List<bool> { true, false, true }, new Func<bool, bool>(x => !x),
                new List<bool> { false, true, false },
            },

            new object[]
            {
                new List<string> { "hello", "world", "!" }, new Func<string, string>(x => x.ToUpper()),
                new List<string> { "HELLO", "WORLD", "!" },
            },

            new object[]
            {
                new List<int> { 1, 2, 3 }, new Func<int, string>(x => x.ToString()),
                new List<string> { "1", "2", "3" },
            },

            new object[]
            {
                new List<string> { "hello", "world", "!" }, new Func<string, int>(s => s.Length),
                new List<int> { 5, 5, 1 },
            },
        };

        /// <summary>
        /// Tests the Map function with various input scenarios.
        /// </summary>
        /// <typeparam name="TInput">The type of elements in the input list.</typeparam>
        /// <typeparam name="TOutput">The type of elements in the output list.</typeparam>
        /// <param name="list">The input list to be mapped.</param>
        /// <param name="func">The mapping function that transforms each element of the input list.</param>
        /// <param name="expectedResult">Expected result after mapping.</param>
        [Test]
        [TestCaseSource(nameof(TestData))]
        public void MapTestCase<TInput, TOutput>(
            List<TInput> list, Func<TInput, TOutput> func, List<TOutput> expectedResult)
        {
            List<TOutput> result = ImplementingFunctions.ImplementingFunctions.Map(list, func);
            Assert.That(result, Is.EqualTo(expectedResult));
        }
    }
}
