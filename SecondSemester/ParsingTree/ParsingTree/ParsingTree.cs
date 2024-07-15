/// <summary>
/// Represents a parsing tree used for evaluating arithmetic expressions.
/// </summary>
/// <remarks>
/// Initializes a new instance of the <see cref="ParsingTree"/> class with the specified root node.
/// </remarks>
/// <param name="rootNode">The root node of the parsing tree.</param>
public class ParsingTree(INode rootNode)
{
    private readonly INode root = rootNode;

    /// <summary>
    /// Evaluates the arithmetic expression represented by the parsing tree.
    /// </summary>
    /// <returns>The result of the arithmetic expression evaluation.</returns>
    public int Evaluate()
    {
        return this.root.Calculate();
    }

    /// <summary>
    /// Prints the arithmetic expression represented by the parsing tree.
    /// </summary>
    public void Print()
    {
        this.root.Print();
        Console.WriteLine();
    }

    /// <summary>
    /// Builds a parsing tree from the given expression.
    /// </summary>
    /// <param name="expression">The arithmetic expression string.</param>
    /// <returns>The parsing tree representing the arithmetic expression.</returns>
    public static ParsingTree? BuildTree(string expression)
    {
        string[] tokens = expression.Split(' ');
        return BuildTree(tokens, ref tokens);
    }

    private static ParsingTree? BuildTree(string[] tokens, ref string[] remainingTokens)
    {
        if (tokens.Length == 0)
        {
            throw new ArgumentException("Invalid expression");
        }

        string token = remainingTokens[0];
        remainingTokens = remainingTokens[1..];

        if (token == "(")
        {
            if (remainingTokens.Length < 3)
            {
                throw new ArgumentException("Invalid expression");
            }

            char operation = Convert.ToChar(remainingTokens[0]);
            remainingTokens = remainingTokens[1..];
            ParsingTree? leftTree = BuildTree(tokens, ref remainingTokens);
            ParsingTree? rightTree = BuildTree(tokens, ref remainingTokens);

            if (leftTree == null || rightTree == null || remainingTokens.Length < 1 || remainingTokens[0] != ")")
            {
                throw new ArgumentException("Invalid expression");
            }

            remainingTokens = remainingTokens[1..];
            return new ParsingTree(new Operator(operation, leftTree.root, rightTree.root));
        }
        else if (token == ")")
        {
            return null;
        }
        else
        {
            return new ParsingTree(new Operand(int.Parse(token)));
        }
    }
}
