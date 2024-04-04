internal class Program
{
    private static void Main()
    {
        var router1 = new Router(1);
        var router2 = new Router(2);
        var router3 = new Router(3);

        router1.Connections.Add(router2, 10);
        router1.Connections.Add(router3, 5);

        router2.Connections.Add(router3, 1);

        List<Router?> routers = [router1, router2, router3];

        var minimumSpanningTree = PrimsAlgorithm.FindMinimumSpanningTree(routers);
        
        Console.WriteLine("Minimum spanning tree:");
        foreach (var edge in minimumSpanningTree)
        {
            Console.WriteLine($"{edge.Item1.Id}: {edge.Item2.Id} ({edge.Item3})");
        }
    }
}
