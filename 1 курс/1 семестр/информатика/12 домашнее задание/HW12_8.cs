using System;
using System.Collections.Generic;

namespace src
{
    public static partial class HW12
    {
        public delegate bool RemoveHashSetDelegate(int a);

        public static HashSet<int> Function8(HashSet<int> intSet, RemoveHashSetDelegate filter)
        {
            HashSet<int> result = new HashSet<int>();

            foreach (var item in intSet)
            {
                if (!filter(item))
                {
                    result.Add(item);
                }
            }

            return result;
        }
    }
}
