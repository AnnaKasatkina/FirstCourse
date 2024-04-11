namespace SparseVectorTests;

public class Tests
{
    [Test]
    public void TestWithNegativeSize()
    {
        Assert.Throws<ArgumentException>(() => new SparseVector.SparseVector(-1));
    }
    
    [Test]
    public void TestWithInvalidIndex()
    {
        var vector = new SparseVector.SparseVector(5);
        Assert.Throws<IndexOutOfRangeException>(() => vector.AddElement(10, 2));
    }
    
    [Test]
    public void TestZeroVector()
    {
        var vector = new SparseVector.SparseVector(5);
        Assert.That(vector.IsZeroVector(), Is.True);
    }
    
    [Test]
    public void TestScalarMultiplication()
    {
        var vector1 = new SparseVector.SparseVector(5);
        vector1.AddElement(0, 2);
        vector1.AddElement(1, 3);

        var vector2 = new SparseVector.SparseVector(5);
        vector2.AddElement(1, 1);
        vector2.AddElement(2, 4);

        var result = vector1.ScalarMultiplication(vector2);

        Assert.That(result, Is.EqualTo(3));
    }
    
    [Test]
    public void TestAdd()
    {
        var vector1 = new SparseVector.SparseVector(5);
        vector1.AddElement(0, 2);
        vector1.AddElement(1, 3);

        var vector2 = new SparseVector.SparseVector(5);
        vector2.AddElement(1, 1);
        vector2.AddElement(2, 4);

        var result = vector1.Add(vector2);

        Assert.That(result.Elements[0], Is.EqualTo(2));
        Assert.That(result.Elements[1], Is.EqualTo(4));
        Assert.That(result.Elements[2], Is.EqualTo(4));
        Assert.That(result.Elements[3], Is.EqualTo(0));
        Assert.That(result.Elements[4], Is.EqualTo(0));
    }
}
