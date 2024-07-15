namespace SparseVector;

/// <summary>
/// Represents a sparse vector with integer elements.
/// </summary>
public class SparseVector
{
    /// <summary>
    /// Gets the elements of the sparse vector represented as key-value pairs, where the key is the index and the value is the element value.
    /// </summary>
    public readonly Dictionary<int, int> Elements;

    /// <summary>
    /// Gets the size of the sparse vector.
    /// </summary>
    public int Size { get; }
    public SparseVector(int size)
    {
        if (size <= 0)
        {
            throw new ArgumentException("The size of the vector must be a positive number");
        }
        Elements = new Dictionary<int, int>();
        Size = size;
    }

    public void AddElement(int index, int value)
    {
        if (index >= Size || index < 0)
        {
            throw new IndexOutOfRangeException("Invalid index");
        }
        if (value != 0)
        {
            Elements[index] = value;
        }
    }

    public SparseVector Add(SparseVector secondVector)
    {
        if (this.Size != secondVector.Size)
        {
            throw new ArgumentException("The size of the vectors must be equal");
        }
        SparseVector result = new SparseVector(this.Size);

        foreach (var item in Elements)
        {
            result.AddElement(item.Key, item.Value);
        }

        foreach (var item in secondVector.Elements)
        {
            if (result.Elements.ContainsKey(item.Key))
            {
                result.Elements[item.Key] += item.Value;
            }
            else
            {
                result.Elements[item.Key] = item.Value;
            }
        }

        return result;
    }

    public SparseVector Subtract(SparseVector secondVector)
    {
        foreach (var item in secondVector.Elements)
        {
            secondVector.Elements[item.Key] = -item.Value;
        }

        return Add(secondVector);
    }

    public int ScalarMultiplication(SparseVector secondVector)
    {
        if (this.Size != secondVector.Size)
        {
            throw new ArgumentException("The size of the vectors must be equal");
        }
        
        int result = 0;
        foreach (var item in secondVector.Elements)
        {
            if (Elements.ContainsKey(item.Key))
            {
                result += item.Value * Elements[item.Key];
            }
        }

        return result;
    }

    public bool IsZeroVector()
    {
        foreach (var item in Elements)
        {
            if (item.Value != 0)
            {
                return false;
            }
        }

        return true;
    }

    public void PrintVector()
    {
        foreach (var item in Elements)
        {
            Console.WriteLine($"Index: {item.Key}, Value: {item.Value}");
        }
    }
}