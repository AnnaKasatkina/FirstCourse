// <copyright file="CalculatorTests.cs" company="PlaceholderCompany">
// Copyright (c) PlaceholderCompany. All rights reserved.
// </copyright>

namespace CalculatorApp
{
    /// <summary>
    /// Class containing tests for the <see cref="Calculator"/> class.
    /// </summary>
    [TestFixture]
    public class CalculatorTests
    {
        /// <summary>
        /// Test verifies the correctness of results for various operations with two numbers.
        /// </summary>
        /// <param name="num1">The first number.</param>
        /// <param name="op">The operator.</param>
        /// <param name="num2">The second number.</param>
        /// <returns>The expected result of the operation.</returns>
        [TestCase('5', '+', '3', ExpectedResult = 8)]
        [TestCase('9', '-', '4', ExpectedResult = 5)]
        [TestCase('6', '×', '2', ExpectedResult = 12)]
        [TestCase('8', '÷', '4', ExpectedResult = 2)]
        public int InputOperator_ValidInputs_ReturnsCorrectResult(char num1, char op, char num2)
        {
            var calc = new Calculator();
            calc.InputNumber(num1);
            calc.InputOperator(op);
            calc.InputNumber(num2);
            calc.InputOperator('=');
            return calc.CurrentValue;
        }

        /// <summary>
        /// Test verifies that division by zero throws a <see cref="DivideByZeroException"/>.
        /// </summary>
        [Test]
        public void InputOperator_DivisionByZero_ThrowsException()
        {
            var calc = new Calculator();
            calc.InputNumber('7');
            calc.InputOperator('÷');
            calc.InputNumber('0');
            Assert.Throws<DivideByZeroException>(() => calc.InputOperator('='));
        }

        /// <summary>
        /// Test verifies the correctness of the result for a chain of operators.
        /// </summary>
        /// <param name="expression">The string representing the expression to be evaluated.</param>
        /// <returns>The expected result of the expression.</returns>
        [TestCase("1+2-1×3÷2", ExpectedResult = 3)]
        public int InputOperator_ChainOperators_CorrectResult(string expression)
        {
            var calc = new Calculator();
            foreach (char c in expression)
            {
                if (c == '+' || c == '-' || c == '×' || c == '÷')
                {
                    calc.InputOperator(c);
                }
                else
                {
                    calc.InputNumber(c);
                }
            }

            calc.InputOperator('=');
            return calc.CurrentValue;
        }

        /// <summary>
        /// Test verifies the correctness of resetting values when clearing the calculator.
        /// </summary>
        [Test]
        public void Clear_ResetCalculator_CorrectValues()
        {
            var calc = new Calculator();
            calc.InputNumber('3');
            calc.InputOperator('+');
            calc.InputNumber('2');
            calc.Clear();
            Assert.That(calc.CurrentValue, Is.EqualTo(0));
            Assert.That(calc.CurrentOperator, Is.EqualTo(' '));
        }
    }
}
