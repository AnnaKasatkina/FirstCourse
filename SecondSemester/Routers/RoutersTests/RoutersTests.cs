using Routers;
using NUnit.Framework;
using System.Collections.Generic;

/// <summary>
/// Tests for the functionality of the routers and Prim's algorithm implementation.
/// </summary>
[TestFixture]
public class RoutersTests
{
    /// <summary>
    /// Verifies that two connected routers return the expected edge.
    /// </summary>
    [Test]
    public void TwoConnectedRouters_ReturnsExpectedEdge()
    {
        var router1 = new Router(1);
        var router2 = new Router(2);
        router1.Connections = new Dictionary<Router, int> { { router2, 10 } };
        router2.Connections = new Dictionary<Router, int> { { router1, 10 } };
        var routers = new List<Router> { router1, router2 };

        var minimumSpanningTree = PrimsAlgorithm.FindMinimumSpanningTree(routers);

        Assert.That(minimumSpanningTree.Count, Is.EqualTo(1));
        Assert.That(minimumSpanningTree[0], Is.EqualTo((router1, router2, 10)));
    }

    /// <summary>
    /// Verifies that an empty list of routers throws an ArgumentOutOfRangeException.
    /// </summary>
    [Test]
    public void EmptyRoutersList_ThrowsArgumentOutOfRangeException()
    {
        var routers = new List<Router>();

        Assert.Throws<System.ArgumentOutOfRangeException>(() => PrimsAlgorithm.FindMinimumSpanningTree(routers));
    }

    /// <summary>
    /// Verifies that a single router returns an empty minimum spanning tree.
    /// </summary>
    [Test]
    public void SingleRouter_ReturnsEmptyMinimumSpanningTree()
    {
        var routers = new List<Router> { new Router(1) };

        var minimumSpanningTree = PrimsAlgorithm.FindMinimumSpanningTree(routers);

        Assert.IsEmpty(minimumSpanningTree);
    }

    /// <summary>
    /// Verifies that when all connections have the same bandwidth, the expected minimum spanning tree is returned.
    /// </summary>
    [Test]
    public void SameBandwidthForAllConnections_ReturnsExpectedMinimumSpanningTree()
    {
        var routers = new List<Router>
            {
                new Router(1),
                new Router(2),
                new Router(3)
            };
        routers[0].Connections = new Dictionary<Router, int>
            {
                { routers[1], 10 },
                { routers[2], 10 }
            };
        routers[1].Connections = new Dictionary<Router, int>
            {
                { routers[0], 10 },
                { routers[2], 10 }
            };
        routers[2].Connections = new Dictionary<Router, int>
            {
                { routers[0], 10 },
                { routers[1], 10 }
            };
        var expectedMinimumSpanningTree = new List<(Router, Router, int)>
            {
                (routers[0], routers[1], 10),
                (routers[0], routers[2], 10)
            };

        var minimumSpanningTree = PrimsAlgorithm.FindMinimumSpanningTree(routers);

        Assert.That(minimumSpanningTree.Count, Is.EqualTo(expectedMinimumSpanningTree.Count));
        foreach (var edge in expectedMinimumSpanningTree)
        {
            Assert.IsTrue(minimumSpanningTree.Contains(edge));
        }
    }
}
