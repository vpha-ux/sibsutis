namespace src;
public static partial class HW12
{
    public delegate bool RemoveHashSetDelegate(int a);
    public static HashSet<int> HashSetFunction8(HashSet<int> intSet, RemoveHashSetDelegate filter)
    {
    HashSet<int> result = new HashSet<int>();
    
    foreach (int num in intSet)
    {
        if (!filter(num))
        {
            result.Add(num);
        }
    }
    
    return result;
    }
}
