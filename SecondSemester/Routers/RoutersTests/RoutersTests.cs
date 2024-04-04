using Routers;

/// <summary>
/// Tests for the Routers namespace.
/// </summary>
[TestFixture]
public class RoutersTests
{
    /// <summary>
    /// Tests the ReadTopology method with a valid input file.
    /// </summary>
    [Test]
    public void ReadTopology_ValidInputFile_ReturnsListOfRouters()
    {
        var inputFile = "valid_topology.txt";
        string[] inputLines = ["1: 2(10), 3(20)", "2: 1(10), 3(30)", "3: 1(20), 2(30)"];
        File.WriteAllLines(inputFile, inputLines);

        var routers = Topology.ReadTopology(inputFile);

        Assert.That(routers, Has.Count.EqualTo(3));
    }

    /// <summary>
    /// Tests the ReadTopology method with an invalid input file.
    /// </summary>
    [Test]
    public void ReadTopology_InvalidInputFile_ReturnsEmptyList()
    {
        var inputFile = "invalid_topology.txt";
        string[] inputLines = ["1: 2(10)", "2(30)", "3: 1(20), 2(30)"];
        File.WriteAllLines(inputFile, inputLines);

        var routers = Topology.ReadTopology(inputFile);

        Assert.That(routers, Is.Empty);
    }

    /// <summary>
    /// Tests the WriteTopology method with a valid output file.
    /// </summary>
    [Test]
    public void WriteTopology_ValidOutputFile_WritesMinimumSpanningTree()
    {
        var outputFile = "output_topology.txt";
        var minimumSpanningTree = new List<(Router, Router, int)>
        {
            (new Router(1), new Router(2), 10),
            (new Router(2), new Router(3), 30)
        };

        Topology.WriteTopology(outputFile, minimumSpanningTree);

        Assert.That(File.Exists(outputFile), Is.True);
    }

    /// <summary>
    /// Tests the WriteTopology method with an empty minimum spanning tree.
    /// </summary>
    [Test]
    public void WriteTopology_EmptyMinimumSpanningTree_DoesNotCreateOutputFile()
    {
        var outputFile = "output_topology.txt";
        var minimumSpanningTree = new List<(Router, Router, int)>();

        Topology.WriteTopology(outputFile, minimumSpanningTree);

        Assert.That(File.Exists(outputFile), Is.False);
    }

    /// <summary>
    /// Tests the FindMinimumSpanningTree method with valid routers.
    /// </summary>
    [Test]
    public void FindMinimumSpanningTree_ValidRouters_ReturnsMinimumSpanningTree()
    {
        var routers = new List<Router>
        {
            new Router(1),
            new Router(2),
            new Router(3)
        };
        routers[0].Connections.Add(routers[1], 10);
        routers[0].Connections.Add(routers[2], 20);
        routers[1].Connections.Add(routers[0], 10);
        routers[1].Connections.Add(routers[2], 30);
        routers[2].Connections.Add(routers[0], 20);
        routers[2].Connections.Add(routers[1], 30);

        var minimumSpanningTree = PrimsAlgorithm.FindMinimumSpanningTree(routers);

        Assert.That(minimumSpanningTree, Has.Count.EqualTo(2));
    }

    /// <summary>
    /// Tests the FindMinimumSpanningTree method with a disconnected graph.
    /// </summary>
    [Test]
    public void FindMinimumSpanningTree_DisconnectedGraph_ThrowsError()
    {
        var routers = new List<Router>
        {
            new Router(1),
            new Router(2),
            new Router(3)
        };

        Assert.Throws<InvalidOperationException>(() => PrimsAlgorithm.FindMinimumSpanningTree(routers));
    }

    /// <summary>
    /// Tests the FindMinimumSpanningTree method with a graph containing only one router.
    /// </summary>
    [Test]
    public void FindMinimumSpanningTree_SingleRouterGraph_ReturnsEmptyTree()
    {
        var routers = new List<Router> { new Router(1) };

        var minimumSpanningTree = PrimsAlgorithm.FindMinimumSpanningTree(routers);

        Assert.That(minimumSpanningTree, Is.Empty);
    }

    /// <summary>
    /// Tests the FindMinimumSpanningTree method with an empty list of routers.
    /// </summary>
    [Test]
    public void FindMinimumSpanningTree_EmptyRouters_ReturnsEmptyTree()
    {
        var routers = new List<Router>();

        var minimumSpanningTree = PrimsAlgorithm.FindMinimumSpanningTree(routers);

        Assert.That(minimumSpanningTree, Is.Empty);
    }
}
