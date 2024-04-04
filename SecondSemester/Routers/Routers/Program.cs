// <copyright file="Program.cs" company="PlaceholderCompany">
// Copyright (c) PlaceholderCompany. All rights reserved.
// </copyright>

namespace Routers;

/// <summary>
/// Represents the main program class.
/// </summary>
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

        var routers = Topology.ReadTopology(inputFile);
        var minimumSpanningTree = PrimsAlgorithm.FindMinimumSpanningTree(routers);

        Topology.WriteTopology(outputFile, minimumSpanningTree);
    }
}