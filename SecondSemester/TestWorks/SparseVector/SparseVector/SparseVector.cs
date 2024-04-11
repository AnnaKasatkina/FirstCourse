namespace SparseVector;

public class SparseVector
{
    private readonly Dictionary<int, int> elements;
    public int Size { get; }
    public SparseVector(int size)
    {
        if (size <= 0)
        {
            throw new ArgumentException("The size of the vector must be a positive number");
        }
        elements = new Dictionary<int, int>();
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
            elements[index] = value;
        }
    }

    public SparseVector Add(SparseVector secondVector)
    {
        if (this.Size != secondVector.Size)
        {
            throw new ArgumentException("The size of the vectors must be equal");
        }
        SparseVector result = new SparseVector(this.Size);

        foreach (var item in elements)
        {
            result.AddElement(item.Key, item.Value);
        }

        foreach (var item in secondVector.elements)
        {
            if (result.elements.ContainsKey(item.Key))
            {
                result.elements[item.Key] += item.Value;
            }
            else
            {
                result.elements[item.Key] = item.Value;
            }
        }

        return result;
    }

    public SparseVector Subtract(SparseVector secondVector)
    {
        foreach (var item in secondVector.elements)
        {
            secondVector.elements[item.Key] = -item.Value;
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
        foreach (var item in secondVector.elements)
        {
            if (elements.ContainsKey(item.Key))
            {
                result += item.Value * elements[item.Key];
            }
        }

        return result;
    }

    public bool IsZeroVector()
    {
        foreach (var item in elements)
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
        foreach (var item in elements)
        {
            Console.WriteLine($"Index: {item.Key}, Value: {item.Value}");
        }
    }
}