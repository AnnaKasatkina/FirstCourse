namespace StackCalculator
{
    public interface IStack
    {
        void Push(double element);
        double Pop();
    }

    public class ArrayStack : IStack
    {
        private double[] array;
        private int top;
        public ArrayStack(int size)
        {
            array = new double[size];
            top = -1;
        }
        public void Push(double element)
        {
            if (top == array.Length - 1)
            {
                throw new StackOverflowException("Stack overflow");
            }
            array[++top] = element;
        }

        public double Pop()
        {
            if (top == -1)
            {
                throw new InvalidOperationException("Stack is empty!");
            }
            return array[top--];
        }
    }

    public class ListStack : IStack
    {
        private List<double> list;

        public ListStack()
        {
            list = new List<double>();
        }

        public void Push(double element)
        {
            list.Add(element);
        }

        public double Pop()
        {
            if (list.Count == 0)
            {
                throw new InvalidOperationException("Stack is empty");
            }
            double element = list[^1];
            list.RemoveAt(list.Count - 1);
            return element;
        }
    }

    public class StackCalculator
    {
        private IStack stack;
        private double epsilon = 1e-10;

        public StackCalculator(IStack stackInstance)
        {
            stack = stackInstance;
        }

        public double Calculate(string expression)
        {
            string[] inputValues = expression.Split(' ');
            foreach (var inputValue in inputValues)
            {
                if (double.TryParse(inputValue, out double operand))
                {
                    stack.Push(operand);
                }
                else
                {
                    double operand2 = stack.Pop();
                    double operand1 = stack.Pop();
                    double result = PerformOperation(inputValue, operand1, operand2);
                    stack.Push(result);
                }
            }
            return stack.Pop();
        }

        private double PerformOperation(string operation, double operand1, double operand2)
        {
            switch (operation)
            {
                case "+":
                    return operand1 + operand2;
                case "-":
                    return operand1 - operand2;
                case "*":
                    return operand1 * operand2;
                case "/":
                    if (Math.Abs(operand2) < epsilon)
                    {
                        throw new DivideByZeroException("Division by zero");
                    }
                    return (double)operand1 / operand2;
                default:
                    throw new ArgumentException("Invalid operator");
            }
        }
    }

    class Program
    {
        static void Main()
        {
            Console.WriteLine("Enter the expression in postfix notation:");
            var expression = Console.ReadLine();
            if (expression == null)
            {
                Console.WriteLine("Error: The input expression is null!");
            }
            else
            {
                try
                {
                    var calculatorWithArrayStack = new StackCalculator(new ArrayStack(expression.Split(' ').Length));
                    double resultWithArrayStack = calculatorWithArrayStack.Calculate(expression);
                    Console.WriteLine("Result with array stack: " + resultWithArrayStack);

                    var calculatorWithListStack = new StackCalculator(new ListStack());
                    double resultWithListStack = calculatorWithListStack.Calculate(expression);
                    Console.WriteLine("Result with list stack: " + resultWithListStack);
                }
                catch (Exception ex)
                {
                    Console.WriteLine("Error: " + ex.Message);
                }
            }
        }
    }
}