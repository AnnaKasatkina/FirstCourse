using SkipList;

SkipList<int> skipList = new SkipList<int>();

skipList.Add(10);
skipList.Add(5);
skipList.Add(20);
skipList.Add(15);

Console.WriteLine("Elements in the SkipList:");
foreach (var element in skipList)
{
    Console.WriteLine(element);
}
