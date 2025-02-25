#include <stdio.h>
#include <stdlib.h>

void Recursion()
{
    int number;
    scanf("%d", &number);
    
    if (number != 0) 
    {
        Recursion();
    }
    if (number > 0)
        {
            printf("%d ", number);
        }
        
}

int main()
{
    Recursion();
}
