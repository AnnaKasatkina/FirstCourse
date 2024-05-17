// <copyright file="ImplementingFunctions.cs" company="PlaceholderCompany">
// Copyright (c) PlaceholderCompany. All rights reserved.
// </copyright>

namespace ImplementingFunctions
{
    /// <summary>
    /// A static class containing methods to implement common functional programming operations such as mapping, filtering, and folding.
    /// </summary>
    public static class ImplementingFunctions
    {
        /// <summary>
        /// Maps each element of the input list to a new value using the specified mapping function.
        /// </summary>
        /// <typeparam name="TOutput">The type of elements in the output list.</typeparam>
        /// <typeparam name="TInput">The type of elements in the input list.</typeparam>
        /// <param name="list">The input list to be mapped.</param>
        /// <param name="func">The mapping function that transforms each element of the input list.</param>
        /// <returns>A list containing the transformed elements.</returns>
        public static List<TOutput> Map<TOutput, TInput>(List<TInput> list, Func<TInput, TOutput> func)
        {
            var mappedList = new List<TOutput>();
            foreach (var item in list)
            {
                mappedList.Add(func(item));
            }

            return mappedList;
        }

        /// <summary>
        /// Filters the elements of the input list based on the specified predicate function.
        /// </summary>
        /// <typeparam name="T">The type of elements in the input and output lists.</typeparam>
        /// <param name="list">The input list to be filtered.</param>
        /// <param name="func">The predicate function that determines whether an element should be included in the output list.</param>
        /// <returns>A list containing the elements that satisfy the predicate.</returns>
        public static List<T> Filter<T>(List<T> list, Func<T, bool> func)
        {
            var filteredList = new List<T>();
            foreach (var item in list)
            {
                if (func(item))
                {
                    filteredList.Add(item);
                }
            }

            return filteredList;
        }

        /// <summary>
        /// Performs a left fold on the elements of the input list using the specified aggregation function and initial value.
        /// </summary>
        /// <typeparam name="TResult">The type of the result of the fold operation.</typeparam>
        /// <typeparam name="T">The type of elements in the input list.</typeparam>
        /// <param name="list">The input list to be folded.</param>
        /// <param name="initialValue">The initial value for the fold operation.</param>
        /// <param name="func">The aggregation function that combines the current fold result with each element of the input list.</param>
        /// <returns>The result of the fold operation.</returns>
        public static TResult Fold<TResult, T>(List<T> list, TResult initialValue, Func<TResult, T, TResult> func)
        {
            var result = initialValue;
            foreach (var item in list)
            {
                result = func(result, item);
            }

            return result;
        }
    }
}
