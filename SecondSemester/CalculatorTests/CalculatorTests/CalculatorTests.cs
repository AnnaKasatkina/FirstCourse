/// <summary>
/// Contains unit tests for the StackCalculator class using different stack implementations.
/// </summary>
[TestClass]
public class CalculatorTests
{
    /// <summary>
    /// Tests the StackCalculator with ArrayStack using a valid expression.
    /// </summary>
    [TestMethod]
    public void TestArrayStackCalculatorWithValidExpression()
    {
        var calculator = new StackCalculator(new ArrayStack(10));

        double result = calculator.Calculate("2 3 + 4 *");

        Assert.AreEqual(20, result, 1e-10);
    }

    /// <summary>
    /// Tests the StackCalculator with ListStack using a valid expression.
    /// </summary>
    [TestMethod]
    public void TestListStackCalculatorWithValidExpression()
    {
        var calculator = new StackCalculator(new ListStack());

        double result = calculator.Calculate("5 2 * 7 +");

        Assert.AreEqual(17, result, 1e-10);
    }

    /// <summary>
    /// Tests the StackCalculator with ArrayStack for a division by zero scenario.
    /// </summary>
    [TestMethod]
    [ExpectedException(typeof(DivideByZeroException))]
    public void TestArrayStackCalculatorDivideByZero()
    {
        var calculator = new StackCalculator(new ArrayStack(5));
        double result = calculator.Calculate("4 0 /");
    }

    /// <summary>
    /// Tests the StackCalculator with ListStack for an invalid operator scenario.
    /// </summary>
    [TestMethod]
    [ExpectedException(typeof(ArgumentException))]
    public void TestListStackCalculatorInvalidOperator()
    {
        var calculator = new StackCalculator(new ListStack());
        double result = calculator.Calculate("3 5 $");
    }

    /// <summary>
    /// Tests the StackCalculator with ArrayStack for an empty expression scenario.
    /// </summary>
    [TestMethod]
    [ExpectedException(typeof(InvalidOperationException))]
    public void TestArrayStackCalculatorEmptyExpression()
    {
        var calculator = new StackCalculator(new ArrayStack(5));
        double result = calculator.Calculate(string.Empty);
    }

    /// <summary>
    /// Tests the StackCalculator with ListStack for a single operand scenario.
    /// </summary>
    [TestMethod]
    public void TestListStackCalculatorSingleOperand()
    {
        var calculator = new StackCalculator(new ListStack());
        double result = calculator.Calculate("42");

        Assert.AreEqual(42, result, 1e-10);
    }

    /// <summary>
    /// Tests the StackCalculator with ArrayStack for multiple operations in the expression.
    /// </summary>
    [TestMethod]
    public void TestArrayStackCalculatorMultipleOperations()
    {
        var calculator = new StackCalculator(new ArrayStack(10));
        double result = calculator.Calculate("3 5 * 2 + 8 /");

        Assert.AreEqual(2.125, result, 1e-10);
    }

    /// <summary>
    /// Tests the StackCalculator with ListStack for a complex expression scenario.
    /// </summary>
    [TestMethod]
    public void TestListStackCalculatorComplexExpression()
    {
        var calculator = new StackCalculator(new ListStack());
        double result = calculator.Calculate("10 2 / 3 5 * +");

        Assert.AreEqual(20, result, 1e-10);
    }

    /// <summary>
    /// Tests the StackCalculator with ListStack for an expression with repeated operations.
    /// </summary>
    [TestMethod]
    public void TestListStackCalculatorRepeatedOperations()
    {
        var calculator = new StackCalculator(new ListStack());
        double result = calculator.Calculate("2 3 * 4 5 * *");

        Assert.AreEqual(120, result, 1e-10);
    }

    /// <summary>
    /// Tests the StackCalculator with ArrayStack for an expression with a mix of positive and negative numbers.
    /// </summary>
    [TestMethod]
    public void TestArrayStackCalculatorWithMixedSigns()
    {
        var calculator = new StackCalculator(new ArrayStack(10));
        double result = calculator.Calculate("-5 3 * 7 -");

        Assert.AreEqual(-22, result, 1e-10);
    }
}
