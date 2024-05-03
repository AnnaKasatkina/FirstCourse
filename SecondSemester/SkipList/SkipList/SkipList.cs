// <copyright file="SkipList.cs" company="Kasatkina Anna">
// Copyright (c) Kasatkina Anna. All rights reserved.
// </copyright>

using System.Collections;

namespace SkipList;

/// <summary>
/// Represents a skip list data structure.
/// </summary>
/// <typeparam name="T">The type of elements in the skip list. It must implement the <see cref="IComparable{T}"/> interface.</typeparam>
public class SkipList<T> : IList<T>
    where T : IComparable<T>?
{
    private const int MaxLevel = 32;
    private readonly Random _random = new Random();
    private Node _head = new Node(MaxLevel);
    private int _count;

    /// <inheritdoc/>
    public int Count => this._count;

    /// <inheritdoc/>
    public bool IsReadOnly => false;

    /// <inheritdoc/>
    public T this[int index]
    {
        get
        {
            if (index < 0 || index >= this._count)
            {
                throw new ArgumentOutOfRangeException(nameof(index));
            }

            Node? current = this._head;
            int level = MaxLevel - 1;

            while (true)
            {
                Node? next = current?.Next[level];
                if (next == null || index < next.Value!.CompareTo(default))
                {
                    if (level == 0 && next != null)
                    {
                        if (next.Value != null) return next.Value;
                    }

                    level--;
                }
                else
                {
                    current = next;
                }
            }
        }
        set => throw new NotSupportedException();
    }

    /// <inheritdoc/>
    public void Add(T element)
    {
        Node?[] update = new Node?[MaxLevel];
        Node? current = this._head;

        for (int i = MaxLevel - 1; i >= 0; i--)
        {
            while (current?.Next[i] != null && current.Next[i].Value!.CompareTo(element) < 0)
            {
                current = current.Next[i];
            }

            update[i] = current;
        }

        var level = this.GetRandomLevel();
        var newNode = new Node(level) { Value = element };

        for (int i = 0; i <= level; i++)
        {
            newNode.Next[i] = update[i] !.Next[i];
            update[i] !.Next[i] = newNode;
        }

        this._count++;
    }

    /// <inheritdoc/>
    public void Clear()
    {
        this._head = new Node(MaxLevel);
        this._count = 0;
    }

    /// <inheritdoc/>
    public bool Contains(T element)
    {
        Node? current = this._head;
        int level = MaxLevel - 1;

        while (true)
        {
            Node? next = current?.Next[level];
            if (element != null && (next == null || element.CompareTo(next.Value) < 0))
            {
                if (level == 0)
                {
                    return false;
                }

                level--;
            }
            else if (next != null && element != null && element.CompareTo(next.Value) == 0)
            {
                return true;
            }
            else
            {
                current = next;
            }
        }
    }

    /// <inheritdoc/>
    public void CopyTo(T[] array, int arrayIndex)
    {
        if (array == null)
        {
            throw new ArgumentNullException(nameof(array));
        }

        if (arrayIndex < 0)
        {
            throw new ArgumentOutOfRangeException(nameof(arrayIndex));
        }

        if (array.Length - arrayIndex < this._count)
        {
            throw new ArgumentException("The number of elements in the source collection is greater than the available space from arrayIndex to the end of the destination array.");
        }

        Node? current = this._head.Next[0];
        while (current != null)
        {
            array[arrayIndex++] = current.Value!;
            current = current.Next[0];
        }
    }

    /// <inheritdoc/>
    public IEnumerator<T> GetEnumerator()
    {
        Node? current = this._head.Next[0];
        while (current != null)
        {
            yield return current.Value!;
            current = current.Next[0];
        }
    }

    /// <inheritdoc/>
    IEnumerator IEnumerable.GetEnumerator()
    {
        return this.GetEnumerator();
    }

    /// <inheritdoc/>
    public int IndexOf(T element)
    {
        Node? current = this._head;
        int level = MaxLevel - 1;
        int index = 0;

        while (true)
        {
            Node? next = current?.Next[level];
            if (next != null && element.CompareTo(next.Value) >= 0)
            {
                if (element.CompareTo(next.Value) == 0)
                {
                    return index;
                }
                else
                {
                    current = next;
                    index++;
                }
            }
            else
            {
                if (level == 0)
                {
                    return -1;
                }

                level--;
            }
        }
    }

    /// <inheritdoc/>
    public void Insert(int index, T element)
    {
        throw new NotSupportedException();
    }

    /// <inheritdoc/>
    public bool Remove(T element)
    {
        throw new NotSupportedException();
    }

    /// <inheritdoc/>
    public void RemoveAt(int index)
    {
        throw new NotSupportedException();
    }

    private int GetRandomLevel()
    {
        int level = 0;
        while (this._random.NextDouble() < 0.5 && level < MaxLevel - 1)
        {
            level++;
        }

        return level;
    }

    private class Node(int level)
    {
        public T? Value { get; set; }

        public Node[] Next { get; } = new Node[level + 1];
    }
}