namespace Routers;

public class Router(int id)
{
    public int Id { get; set; } = id;
    public Dictionary<Router, int> Connections { get; set; } = new();
}