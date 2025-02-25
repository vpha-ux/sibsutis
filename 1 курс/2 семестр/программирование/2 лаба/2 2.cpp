#include <stdio.h>
#include <stdlib.h>

void Recursion(int Array[], int number)
{
    number--;
    
    if (number<0) 
    {
        return;
    }
    
    if (Array[number]  < 0)
    {
        printf("%d ", Array[number]);
        Recursion(Array, number);
    }

    if (Array[number] > 0)
    {
       Recursion(Array, number);
       printf("%d ", Array[number]);
    }
}



int main()
{

    int Array[10] = {1,-5,89,-53,82,9,45,-56,74,150};
    Recursion(Array, 10);
    return 0;
}
