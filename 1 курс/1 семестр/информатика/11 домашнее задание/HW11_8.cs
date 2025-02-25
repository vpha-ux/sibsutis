namespace src;

public static partial class HW11
{
    public static int[] Function8(int[] array)
    {
        int count = 0;
        for (int i = 0; i < array.GetLength(0); i++){
            if (array[i]>0){
                count +=1;
            }
        }
        int[] result = new int[count];
        for (int i = 0, j = 0; i < array.GetLength(0); i++)
        {
            if (array[i] > 0) {
                result[j] = array[i];
                j += 1;
            }
        }
    return result;
    }
}
