public class Router
{
    public int Id { get; set; }
    public Dictionary<Router, int> Connections { get; set; }

    public Router(int id)
    {
        Id = id;
        Connections = new Dictionary<Router, int>();
    }
}