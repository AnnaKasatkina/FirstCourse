public static class PrimsAlgorithm
{
    public static List<(Router, Router, int)> FindMinimumSpanningTree(List<Router?> routers)
    {
        var visited = new HashSet<Router?>();
        var minimumSpanningTree = new List<(Router, Router, int)>();

        var startRouter = routers[0];
        visited.Add((startRouter));

        while (visited.Count < routers.Count)
        {
            var minWeight = int.MaxValue;
            Router? minFrom = null;
            Router? minTo = null;

            foreach (var router in visited)
            {
                if (router == null) continue;
                foreach (var connection in router.Connections)
                {
                    if (!visited.Contains(connection.Key) && connection.Value < minWeight)
                    {
                        minWeight = connection.Value;
                        minFrom = router;
                        minTo = connection.Key;
                    }
                }
            }

            if (minTo != null)
            {
                minimumSpanningTree.Add((minFrom, minTo, minWeight));
                visited.Add(minTo);
            }
            else
            {
                Console.Error.WriteLine("Error: Network is not connected!");
                Environment.Exit(1);
            }
        }

        return minimumSpanningTree;
    }
}
