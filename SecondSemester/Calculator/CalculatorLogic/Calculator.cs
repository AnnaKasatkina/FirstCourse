// <copyright file="Calculator.cs" company="PlaceholderCompany">
// Copyright (c) PlaceholderCompany. All rights reserved.
// </copyright>

namespace CalculatorApp
{
    /// <summary>
    /// Represents a simple calculator.
    /// </summary>
    public class Calculator
    {
        private bool isNewNumber = true;
        private string currentNumber = string.Empty;
        private char currentOperator = ' ';
        private int currentValue = 0;
        private int storedValue = 0;

        /// <summary>
        /// Gets the current value in the calculator.
        /// </summary>
        public int CurrentValue => this.currentValue;

        /// <summary>
        /// Gets the current operator in the calculator.
        /// </summary>
        public char CurrentOperator => this.currentOperator;

        /// <summary>
        /// Inputs a new number into the calculator.
        /// </summary>
        /// <param name="newNumber">The new number to input.</param>
        public void InputNumber(char newNumber)
        {
            if (this.isNewNumber)
            {
                this.currentNumber = string.Empty;
                this.isNewNumber = false;
            }

            this.currentNumber += newNumber;
        }

        /// <summary>
        /// Inputs a new operator into the calculator.
        /// </summary>
        /// <param name="newOperator">The new operator to input.</param>
        public void InputOperator(char newOperator)
        {
            this.isNewNumber = true;
            if (!int.TryParse(this.currentNumber, out this.currentValue))
            {
                throw new ArgumentException("Invalid input format", nameof(this.currentNumber));
            }

            this.CalculateResult();

            if (newOperator != '=')
            {
                this.currentOperator = newOperator;
            }
        }

        /// <summary>
        /// Calculates the result based on the current operator.
        /// </summary>
        public void CalculateResult()
        {
            switch (this.currentOperator)
            {
                case '+':
                    this.currentValue = this.storedValue + this.currentValue;
                    break;
                case '-':
                    this.currentValue = this.storedValue - this.currentValue;
                    break;
                case '×':
                    this.currentValue = this.storedValue * this.currentValue;
                    break;
                case '÷':
                    if (this.currentValue != 0)
                    {
                        this.currentValue = this.storedValue / this.currentValue;
                    }
                    else
                    {
                        throw new DivideByZeroException("Error: Division by zero");
                    }

                    break;
                default:
                    break;
            }

            this.storedValue = this.currentValue;
        }

        /// <summary>
        /// Clears the calculator, resetting its values.
        /// </summary>
        public void Clear()
        {
            this.currentValue = 0;
            this.storedValue = 0;
            this.currentOperator = ' ';
        }
    }
}
