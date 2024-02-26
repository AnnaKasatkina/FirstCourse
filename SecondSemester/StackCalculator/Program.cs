interface Stack
{
    void Push(int element);
    int Pop();
}

class ArrayStack : Stack
{
    private int[] array;
    private int top;
    public ArrayStack(int size)
    {
        array = new int[size];
        top = -1;
    }
    public void Push(int element)
    {
        if (top == array.Length - 1)
        {
            throw new StackOverflowException("Stack overflow");
        }
        array[++top] = element;
    }

    public int Pop()
    {
        if (top == -1)
        {
            throw new InvalidOperationException("Stack is empty!");
        }
        return array[top--];
    }
}

class ListStack : Stack
{
    List<int> list;

    public ListStack()
    {
        list = new List<int>();
    }

    public void Push(int element)
    {
        list.Add(element);
    }

    public int Pop()
    {
        if (list.Count == 0)
        {
            throw new InvalidOperationException("Stack is empty");
        }
        int element = list[^1];
        list.RemoveAt(list.Count - 1);
        return element;
    }
}

class StackCalculator
{
    private Stack stack;
    private double epsilon = 1e-10;

    public StackCalculator(Stack stackInstance)
    {
        stack = stackInstance;
    }

    public double Calculate(string expression)
    {
        string[] inputValues = expression.Split(' ');
        foreach (var inputValue in inputValues)
        {
            if (int.TryParse(inputValue, out int operand))
            {
                stack.Push(operand);
            }
            else
            {
                int operand2 = stack.Pop();
                int operand1 = stack.Pop();
                double result = PerformOperation(inputValue, operand1, operand2);
                stack.Push(result);
            }
        }
        return stack.Pop;
    }

    private double PerformOperation(string operation, int operand1, int operand2)
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
    }
}