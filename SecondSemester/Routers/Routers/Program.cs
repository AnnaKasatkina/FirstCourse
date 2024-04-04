namespace Routers;

internal static class Program
{
    private static void Main(string[] args)
    {
        if (args.Length != 2)
        {
            Console.WriteLine("Usage: program input_file output_file");
            return;
        }

        var inputFile = args[0];
        var outputFile = args[1];

        List<Router> routers = Topology.ReadTopology(inputFile);
        var minimumSpanningTree = PrimsAlgorithm.FindMinimumSpanningTree(routers);
        
        Topology.WriteTopology(outputFile, minimumSpanningTree);
    }
}
