// <copyright file="TestPriorityQueue.cs" company="Kasatkina Anna">
// Copyright (c) Kasatkina Anna. All rights reserved.
// </copyright>

/// <summary>
/// Contains unit tests for the <see cref="PriorityQueue{T}"/> class.
/// </summary>
public class TestPriorityQueue
{
    /// <summary>
    /// Tests adding a single item to the priority queue.
    /// </summary>
    [Test]
    public void SingleItem()
    {
        var priorityQueue = new PriorityQueue<int>();

        priorityQueue.Enqueue(5, 1);

        Assert.IsFalse(priorityQueue.Empty);
        Assert.That(priorityQueue.Dequeue(), Is.EqualTo(5));
        Assert.IsTrue(priorityQueue.Empty);
    }

    /// <summary>
    /// Tests adding  two items with the same priority are added to the priority queue.
    /// </summary>
    [Test]
    public void SamePriorities()
    {
        var priorityQueue = new PriorityQueue<string>();

        priorityQueue.Enqueue("Item 1", 20);
        priorityQueue.Enqueue("Item 2", 20);

        Assert.IsFalse(priorityQueue.Empty);
        Assert.That(priorityQueue.Dequeue(), Is.EqualTo("Item 1"));
        Assert.That(priorityQueue.Dequeue(), Is.EqualTo("Item 2"));
        Assert.IsTrue(priorityQueue.Empty);
    }

    /// <summary>
    /// Tests adding multiple items to the priority queue.
    /// </summary>
    [Test]
    public void MultipleItems()
    {
        var priorityQueue = new PriorityQueue<string>();

        priorityQueue.Enqueue("Item 3", 1);
        priorityQueue.Enqueue("Item 2", 2);
        priorityQueue.Enqueue("Item 1", 3);

        Assert.IsFalse(priorityQueue.Empty);
        Assert.That(priorityQueue.Dequeue(), Is.EqualTo("Item 1"));
        Assert.That(priorityQueue.Dequeue(), Is.EqualTo("Item 2"));
        Assert.That(priorityQueue.Dequeue(), Is.EqualTo("Item 3"));
        Assert.IsTrue(priorityQueue.Empty);
    }

    /// <summary>
    /// Tests attempting to dequeue from an empty priority queue.
    /// </summary>
    [Test]
    public void EmptyQueue()
    {
        var priorityQueue = new PriorityQueue<double>();

        Assert.IsTrue(priorityQueue.Empty);
        Assert.Throws<InvalidOperationException>(() => priorityQueue.Dequeue());
    }
}
