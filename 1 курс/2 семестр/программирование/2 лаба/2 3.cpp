#include <stdio.h>
#include <stdlib.h>


void b(int number)
{
    if (number < 1)
    {
        return;
    }
    
    else
    {
    	b(number/2);
    	printf("%d", number % 2);
    }

}

int main()
{
    int number;
    scanf("%d", &number);
    b(number);
    return 0;
}
