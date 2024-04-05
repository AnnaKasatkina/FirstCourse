namespace CalculatorApp
{
    public class Calculator
    {
        private bool isNewNumber = true;

        private string currentNumber = string.Empty;
        private int currentValue = 0;
        private int storedValue = 0;
        private char currentOperator = ' ';

        public int CurrentValue => currentValue;
        public char CurrentOperator => currentOperator;

        public void InputNumber(char newNumber)
        {
            if (isNewNumber)
            {
                currentNumber = string.Empty;
                isNewNumber = false;
            }
            currentNumber += newNumber;
        }

        public void InputOperator(char newOperator)
        {
            isNewNumber = true;
            if (!int.TryParse(currentNumber, out currentValue))
            {
                throw new ArgumentException("Invalid input format", nameof(currentNumber));
            }

            CalculateResult();

            if (newOperator != '=')
            {
                currentOperator = newOperator;
            }
        }

        public void CalculateResult()
        {
            switch (currentOperator)
            {
                case '+':
                    currentValue = storedValue + currentValue;
                    break;
                case '-':
                    currentValue = storedValue - currentValue;
                    break;
                case '×':
                    currentValue = storedValue * currentValue;
                    break;
                case '÷':
                    if (currentValue != 0)
                    {
                        currentValue = storedValue / currentValue;
                    }
                    else
                    {
                        throw new DivideByZeroException("Error: Division by zero");
                    }
                    break;
                default:
                    break;
            }

            storedValue = currentValue;
        }

        public void Clear()
        {
            currentValue = 0;
            storedValue = 0;
            currentOperator = ' ';
        }
    }
}
