// <copyright file="SkipListTests.cs" company="Kasatkina Anna">
// Copyright (c) Kasatkina Anna. All rights reserved.
// </copyright>

using SkipList;

namespace SkipListTests
{
    /// <summary>
    /// Tests for the SkipList class.
    /// </summary>
    [TestFixture]
    public class SkipListTests
    {
        /// <summary>
        /// Test to verify that adding a single element increases the count of the SkipList.
        /// </summary>
        [Test]
        public void Add_Element_CountIncreases()
        {
            var skipList = new SkipList<int> { 10 };
            Assert.That(skipList.Count, Is.EqualTo(1));
        }

        /// <summary>
        /// Test to verify that adding multiple elements increases the count of the SkipList accordingly.
        /// </summary>
        [Test]
        public void Add_MultipleElements_CountIncreases()
        {
            var skipList = new SkipList<int>
            {
                10,
                20,
                30
            };
            Assert.That(skipList.Count, Is.EqualTo(3));
        }

        /// <summary>
        /// Test to verify that Contains method returns true for an existing element in the SkipList.
        /// </summary>
        [Test]
        public void Contains_ReturnsTrueForExistingElement()
        {
            var skipList = new SkipList<int> { 10 };
            Assert.IsTrue(skipList.Contains(10));
        }

        /// <summary>
        /// Test to verify that Contains method returns false for a non-existing element in the SkipList.
        /// </summary>
        [Test]
        public void Contains_ReturnsFalseForNonExistingElement()
        {
            var skipList = new SkipList<int> { 10 };
            Assert.That(skipList, Does.Not.Contain(20));
        }

        /// <summary>
        /// Test to verify that accessing an invalid index through the indexer throws an ArgumentOutOfRangeException.
        /// </summary>
        [Test]
        public void Indexer_ThrowsExceptionForInvalidIndex()
        {
            var skipList = new SkipList<int>();
            if (skipList == null) throw new ArgumentNullException(nameof(skipList));
            Assert.Throws<ArgumentOutOfRangeException>(() =>
            {
                var value = skipList[-1];
            });
        }

        /// <summary>
        /// Test to verify that copying elements to an array with a negative index throws an ArgumentOutOfRangeException.
        /// </summary>
        [Test]
        public void CopyTo_ThrowsExceptionIfArrayIndexIsNegative()
        {
            var skipList = new SkipList<int>();
            if (skipList == null) throw new ArgumentNullException(nameof(skipList));
            Assert.Throws<ArgumentOutOfRangeException>(() =>
            {
                skipList.CopyTo(new int[3], -1);
            });
        }

        /// <summary>
        /// Test to verify that copying elements to an array with insufficient space throws an ArgumentException.
        /// </summary>
        [Test]
        public void CopyTo_ThrowsExceptionIfNotEnoughSpaceInArray()
        {
            var skipList = new SkipList<int>
            {
                10,
                20
            };
            Assert.Throws<ArgumentException>(() =>
            {
                skipList.CopyTo(new int[1], 0);
            });
        }

        /// <summary>
        /// Test to verify that IndexOf method returns the correct index for an existing element in the SkipList.
        /// </summary>
        [Test]
        public void IndexOf_ReturnsCorrectIndexForExistingElement()
        {
            var skipList = new SkipList<int>
            {
                10,
                20
            };
            Assert.That(skipList.IndexOf(20), Is.EqualTo(1));
        }

        /// <summary>
        /// Test to verify that IndexOf method returns -1 for a non-existing element in the SkipList.
        /// </summary>
        [Test]
        public void IndexOf_ReturnsMinusOneForNonExistingElement()
        {
            var skipList = new SkipList<int>
            {
                10,
                20
            };
            Assert.That(skipList.IndexOf(30), Is.EqualTo(-1));
        }
    }
}
