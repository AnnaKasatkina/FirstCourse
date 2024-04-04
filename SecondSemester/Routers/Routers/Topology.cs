namespace Routers;

public static class Topology
{
    public static List<Router> ReadTopology(string inputFile)
    {
        var routers = new List<Router>();

        foreach (var line in File.ReadLines(inputFile))
        {
            var parts = line.Split(':');
            var id = int.Parse(parts[0]);
            var router = new Router(id);
            routers.Add(router);

            foreach (var connection in parts[1].Split(','))
            {
                var subparts = connection.Trim().Split('(');
                var connectedId = int.Parse(subparts[0]);
                var bandwidth = int.Parse(subparts[1].Trim(')'));
                var connectedRouter = routers.FirstOrDefault(r => r.Id == connectedId);
                if (connectedRouter != null)
                    router.Connections.Add(connectedRouter, bandwidth);
            }
        }

        return routers;
    }

    public static void WriteTopology(string outputFile, List<(Router, Router, int)> minimumSpanningTree)
    {
        using var writer = new StreamWriter(outputFile);
        foreach (var edge in minimumSpanningTree)
        {
            writer.WriteLine($"{edge.Item1.Id}: {edge.Item2.Id} ({edge.Item3})");
        }
    }

}