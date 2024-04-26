// <copyright file="PriorityQueue.cs" company="Kasatkina Anna">
// Copyright (c) Kasatkina Anna. All rights reserved.
// </copyright>

/// <summary>
/// Represents a priority queue data structure that stores elements with associated priorities.
/// </summary>
/// <typeparam name="T">The type of elements stored in the priority queue.</typeparam>
public class PriorityQueue<T>
{
    private readonly List<(int priority, T item)> heap;

    /// <summary>
    /// Initializes a new instance of the <see cref="PriorityQueue{T}"/> class.
    /// </summary>
    public PriorityQueue()
    {
        this.heap = new List<(int priority, T item)>();
    }

    /// <summary>
    /// Gets a value indicating whether the priority queue is empty.
    /// </summary>
    public bool Empty => this.heap.Count == 0;

    /// <summary>
    /// Adds an element to the priority queue with the specified priority.
    /// </summary>
    /// <param name="value">The element to add to the priority queue.</param>
    /// <param name="priority">The priority of the element.</param>
    public void Enqueue(T value, int priority)
    {
        this.heap.Add((priority, value));
        var currentIndex = this.heap.Count - 1;

        while (currentIndex > 0)
        {
            var parentIndex = (currentIndex - 1) / 2;
            if (this.heap[parentIndex].priority >= this.heap[currentIndex].priority)
            {
                break;
            }

            (this.heap[parentIndex], this.heap[currentIndex]) = (this.heap[currentIndex], this.heap[parentIndex]);
            currentIndex = parentIndex;
        }
    }

    /// <summary>
    /// Removes and returns the element with the highest priority from the priority queue.
    /// </summary>
    /// <returns>The element with the highest priority.</returns>
    /// <exception cref="InvalidOperationException">Thrown when the priority queue is empty.</exception>
    public T Dequeue()
    {
        if (this.Empty)
        {
            throw new InvalidOperationException("Queue is empty!");
        }

        var lastIndex = this.heap.Count - 1;
        (this.heap[0], this.heap[lastIndex]) = (this.heap[lastIndex], this.heap[0]);

        var dequeuedItem = this.heap[lastIndex];
        this.heap.RemoveAt(lastIndex);

        var currentIndex = 0;
        while (true)
        {
            var leftChildIndex = (2 * currentIndex) + 1;
            var rightChildIndex = (2 * currentIndex) + 2;

            if (leftChildIndex >= this.heap.Count)
            {
                break;
            }

            var swapIndex = leftChildIndex;

            if (rightChildIndex < this.heap.Count &&
                this.heap[rightChildIndex].priority > this.heap[leftChildIndex].priority)
            {
                swapIndex = rightChildIndex;
            }

            if (this.heap[currentIndex].priority >= this.heap[swapIndex].priority)
            {
                break;
            }

            (this.heap[currentIndex], this.heap[swapIndex]) = (this.heap[swapIndex], this.heap[currentIndex]);
            currentIndex = swapIndex;
        }

        return dequeuedItem.item;
    }
}
