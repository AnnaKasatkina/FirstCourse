// <copyright file="Topology.cs" company="PlaceholderCompany">
// Copyright (c) PlaceholderCompany. All rights reserved.
// </copyright>

namespace Routers;

/// <summary>
/// A static class providing methods for working with network topology.
/// </summary>
public static class Topology
{
    /// <summary>
    /// Reads network topology from the specified file.
    /// </summary>
    /// <param name="inputFile">The path to the input file containing network topology.</param>
    /// <returns>A list of routers representing the network topology.</returns>
    public static List<Router> ReadTopology(string inputFile)
    {
        var routers = new List<Router>();

        foreach (var line in File.ReadLines(inputFile))
        {
            var parts = line.Trim().Split(':');
            if (parts.Length == 0 || parts.Length != 2)
            {
                continue;
            }

            var id = int.Parse(parts[0]);
            var router = routers.FirstOrDefault(r => r.Id == id);
            if (router == null)
            {
                router = new Router(id);
                routers.Add(router);
            }

            foreach (var connection in parts[1].Split(','))
            {
                var subparts = connection.Trim().Split('(');
                if (subparts.Length != 2)
                {
                    continue;
                }

                var connectedId = int.Parse(subparts[0]);
                var bandwidth = int.Parse(subparts[1].Trim(')'));

                var connectedRouter = routers.FirstOrDefault(r => r.Id == connectedId);
                if (connectedRouter == null)
                {
                    connectedRouter = new Router(connectedId);
                    routers.Add(connectedRouter);
                }

                router.Connections.Add(connectedRouter, bandwidth);
            }
        }

        return routers;
    }

    /// <summary>
    /// Writes minimum spanning tree of the network topology to the specified file.
    /// </summary>
    /// <param name="outputFile">The path to the output file to write the minimum spanning tree.</param>
    /// <param name="minimumSpanningTree">The minimum spanning tree to write.</param>
    public static void WriteTopology(string outputFile, List<(Router, Router, int)> minimumSpanningTree)
    {
        using var writer = new StreamWriter(outputFile);
        foreach (var edge in minimumSpanningTree)
        {
            writer.WriteLine($"{edge.Item1.Id}: {edge.Item2.Id} ({edge.Item3})");
        }
    }
}
