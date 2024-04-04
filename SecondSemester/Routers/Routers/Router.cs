// <copyright file="Router.cs" company="PlaceholderCompany">
// Copyright (c) PlaceholderCompany. All rights reserved.
// </copyright>

namespace Routers;

public class Router
{
    /// <summary>
    /// Initializes a new instance of the <see cref="Router"/> class with the specified ID.
    /// </summary>
    /// <param name="id">The ID of the router.</param>
    public Router(int id)
    {
        this.Id = id;
    }

    /// <summary>
    /// Gets or sets the ID of the router.
    /// </summary>
    public int Id { get; set; }

    /// <summary>
    /// Gets or sets the connections of the router to other routers along with their bandwidths.
    /// </summary>
    public Dictionary<Router, int> Connections { get; set; } = new Dictionary<Router, int>();
}