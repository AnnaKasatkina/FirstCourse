// <copyright file="CalculatorTests.cs" company="PlaceholderCompany">
// Copyright (c) PlaceholderCompany. All rights reserved.
// </copyright>

/// <summary>
/// Contains unit tests for the StackCalculator class using different stack implementations.
/// </summary>
[TestClass]
public class CalculatorTests
{
    private StackCalculator calculator;

    /// <summary>
    /// Initializes a new instance of the <see cref="CalculatorTests"/> class.
    /// Initializes the calculator with ArrayStack for all test cases.
    /// </summary>
    public CalculatorTests()
    {
        this.calculator = new StackCalculator(new ArrayStack(10));
    }

    /// <summary>
    /// Tests the StackCalculator with ArrayStack for various expressions.
    /// </summary>
    [DataTestMethod]
    [DataRow("2 3 + 4 *", 20)]
    [DataRow("3 5 * 2 + 8 /", 2.125)]
    [DataRow("-5 3 * 7 -", -22)]
    public void TestArrayStackCalculator(string expression, double expected)
    {
        double result = this.calculator.Calculate(expression);
        Assert.AreEqual(expected, result, 1e-10);
    }

    /// <summary>
    /// Tests the StackCalculator with ListStack for various expressions.
    /// </summary>
    [DataTestMethod]
    [DataRow("5 2 * 7 +", 17)]
    [DataRow("10 2 / 3 5 * +", 20)]
    [DataRow("2 3 * 4 5 * *", 120)]
    public void TestListStackCalculator(string expression, double expected)
    {
        this.calculator = new StackCalculator(new ListStack());
        double result = this.calculator.Calculate(expression);
        Assert.AreEqual(expected, result, 1e-10);
    }
}
