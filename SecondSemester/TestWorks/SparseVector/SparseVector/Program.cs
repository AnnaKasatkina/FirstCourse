namespace SparseVector
{
    internal static class Program
    {
        private static void Main()
        {
            var vector1 = new SparseVector(5);
            vector1.AddElement(0, 2);
            vector1.AddElement(3, 4);
            vector1.AddElement(4, 6);

            Console.WriteLine("Первый вектор:");
            vector1.PrintVector();
            Console.WriteLine();

            var vector2 = new SparseVector(5);
            vector2.AddElement(1, 3);
            vector2.AddElement(2, 5);
            vector2.AddElement(4, 2);

            Console.WriteLine("Второй вектор:");
            vector2.PrintVector();
            Console.WriteLine();

            var sum = vector1.Add(vector2);
            Console.WriteLine("Результат сложения:");
            sum.PrintVector();
            Console.WriteLine();

            var difference = vector1.Subtract(vector2);
            Console.WriteLine("Результат вычитания:");
            difference.PrintVector();
            Console.WriteLine();

            var scalarProduct = vector1.ScalarMultiplication(vector2);
            Console.WriteLine($"Скалярное произведение: {scalarProduct}");
            Console.WriteLine();

            Console.WriteLine($"Первый вектор - нулевой: {vector1.IsZeroVector()}");
            Console.WriteLine($"Второй вектор - нулевой: {vector2.IsZeroVector()}");

            Console.ReadLine();
        }
    }
}