/// <summary>
/// Test fixture for unit testing the ParsingTree class.
/// </summary>
[TestFixture]
public class ParsingTreeTests
{
    /// <summary>
    /// Tests a simple arithmetic expression.
    /// </summary>
    [Test]
    public void TestSimpleExpression()
    {
        string expression = "( * ( + 1 1 ) 2 )";
        ParsingTree? tree = ParsingTree.BuildTree(expression);
        int result;

        if (tree != null)
        {
            result = tree.Evaluate();
            Assert.That(result, Is.EqualTo(4));
        }
    }

    /// <summary>
    /// Tests division by zero scenario.
    /// </summary>
    [Test]
    public void TestDivisionByZero()
    {
        string expression = "( / 1 0 )";
        ParsingTree? tree = ParsingTree.BuildTree(expression);

        // Check if tree is not null before attempting to evaluate
        if (tree != null)
        {
            Assert.Throws<DivideByZeroException>(() => tree.Evaluate());
        }
        else
        {
            Assert.Fail("ParsingTree.BuildTree returned null.");
        }
    }

        /// <summary>
        /// Tests an invalid expression scenario.
        /// </summary>
        [Test]
    public void TestInvalidExpression()
    {
        string expression = "( * 1 2 3 )";
        Assert.Throws<ArgumentException>(() => ParsingTree.BuildTree(expression));
    }

    /// <summary>
    /// Tests a subtraction operation resulting in a negative number.
    /// </summary>
    [Test]
    public void TestNegativeResult()
    {
        string expression = "( - 5 10 )";
        ParsingTree? tree = ParsingTree.BuildTree(expression);
        int result;

        if (tree != null)
        {
            result = tree.Evaluate();
            Assert.That(result, Is.EqualTo(-5));
        }
    }

    /// <summary>
    /// Tests a complex arithmetic expression.
    /// </summary>
    [Test]
    public void TestComplexExpression()
    {
        string expression = "( * ( + 1 1 ) ( / 10 5 ) )";
        ParsingTree? tree = ParsingTree.BuildTree(expression);
        int result;

        if (tree != null)
        {
            result = tree.Evaluate();
            Assert.That(result, Is.EqualTo(4));
        }
    }

    /// <summary>
    /// Tests a large arithmetic expression.
    /// </summary>
    [Test]
    public void TestLargeExpression()
    {
        string expression = "( * ( + 1 ( * 2 3 ) ) ( - 10 5 ) )";
        ParsingTree? tree = ParsingTree.BuildTree(expression);
        int result;

        if (tree != null)
        {
            result = tree.Evaluate();
            Assert.That(result, Is.EqualTo(35));
        }
    }

    /// <summary>
    /// Tests an expression multiplying by zero.
    /// </summary>
    [Test]
    public void TestZeroExpression()
    {
        string expression = "( * 0 10 )";
        ParsingTree? tree = ParsingTree.BuildTree(expression);
        int result;

        if (tree != null)
        {
            result = tree.Evaluate();
            Assert.That(result, Is.EqualTo(0));
        }
    }

    /// <summary>
    /// Tests a single operand expression.
    /// </summary>
    [Test]
    public void TestSingleOperandExpression()
    {
        string expression = "3";
        ParsingTree? tree = ParsingTree.BuildTree(expression);
        int result;

        if (tree != null)
        {
            result = tree.Evaluate();
            Assert.That(result, Is.EqualTo(3));
        }
    }

    /// <summary>
    /// Tests a single operator expression.
    /// </summary>
    [Test]
    public void TestSingleOperatorExpression()
    {
        string expression = "( + 3 5 )";
        ParsingTree? tree = ParsingTree.BuildTree(expression);
        int result;

        if (tree != null)
        {
            result = tree.Evaluate();
            Assert.That(result, Is.EqualTo(8));
        }
    }
}
