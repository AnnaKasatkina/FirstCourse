internal class Program
{
    private static void Main()
    {
        var routers = new List<Router>();

        var router1 = new Router(1);
        var router2 = new Router(2);
        var router3 = new Router(3);
        
        router1.Connections.Add(router2, 10);
        router1.Connections.Add(router3, 5);
        
        router2.Connections.Add(router1, 10);
        router2.Connections.Add(router3, 1);
        
        router3.Connections.Add(router1,5);
        router3.Connections.Add(router2,1);
    }
}