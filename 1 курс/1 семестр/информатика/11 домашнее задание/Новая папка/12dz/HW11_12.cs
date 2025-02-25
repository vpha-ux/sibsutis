namespace src
{
    public static partial class HW11
    {
        public static int Function12(int[] array)
        {
            if (array.Length == 0) 
            { 
                return 0; 
            }
            else
            { 
                int maxEven = int.MinValue; 
 
                foreach (int num in array) 
                { 
                    if (num % 2 == 0 && num > maxEven) 
                    { 
                        maxEven = num; 
                    } 
                } 
 
                return maxEven;
            }
        }
    }
}