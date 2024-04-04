// <copyright file="PrimsAlgorithm.cs" company="PlaceholderCompany">
// Copyright (c) PlaceholderCompany. All rights reserved.
// </copyright>

namespace Routers;

/// <summary>
/// Provides methods for finding the minimum spanning tree of a network topology using Prim's algorithm.
/// </summary>
public static class PrimsAlgorithm
{
    /// <summary>
    /// Finds the minimum spanning tree of the network topology using Prim's algorithm.
    /// </summary>
    /// <param name="routers">The list of routers representing the network topology.</param>
    /// <returns>The minimum spanning tree as a list of edges.</returns>
    public static List<(Router, Router, int)> FindMinimumSpanningTree(List<Router> routers)
    {
        var visited = new HashSet<Router>();
        var minimumSpanningTree = new List<(Router, Router, int)>();

        var startRouter = routers[0];
        visited.Add(startRouter);

        while (visited.Count < routers.Count)
        {
            var minWeight = int.MaxValue;
            Router? minFrom = null;
            Router? minTo = null;

            foreach (var router in visited)
            {
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

            if (minTo != null && minFrom != null)
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