#include <stdio.h>
#include <string.h>

struct abonent
{
    char surname[20];
    char name[20];
    char patronymic[20];
    long long phone;  
    long long phone2;  
};

int less(struct abonent x, struct abonent y)
{
    if (strcmp(x.name, y.name) < 0) 
    {
        return 1;
    }
    else if (strcmp(x.name, y.name) > 0)
    {
        return 0;
    }
    else if (strcmp(x.surname, y.surname) < 0)
    {
        return 1;
    }
    else if (x.phone > y.phone) 
    {
        return 0;
    }
    else if (x.phone < y.phone)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void InsertSort(struct abonent* A)
{
    for (int i = 1; i < 4; i++)
    {
        struct abonent temp = A[i];
        int j = i - 1;
        
        while (j >= 0 && less(temp, A[j]))
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        
        A[j + 1] = temp;
    }
}

int main()
{
    struct abonent A[4] = 
    { 
        { "Hovalyg", "Krictina", "Igorevna", 89466465314584LL, 0 },
        { "Sergeeva", "Victoria", "Pavlovna", 89145341864313LL, 9685786969LL },
        { "Shagalieva", "Anastasia", "Alekseevna", 8982414541643LL, 0 },
        { "Speshilova", "Valeria", "Dmitrievna", 8254135141324LL, 0 }
    };
    
    printf("Исходный справочник:\n");
    
    for (int i = 0; i < 4; i++) 
    {
        printf(" %s  %s  %s %lld  %lld\n", A[i].name, A[i].surname, A[i].patronymic, A[i].phone, A[i].phone2);
    }
    
    printf("\n");
    
    InsertSort(A);

    printf("Cправочник, отсортированного по сложному ключу:\n");
    
    for (int i = 0; i < 4; i++) 
    {
        printf(" %s  %s  %s %lld  %lld\n", A[i].name, A[i].surname, A[i].patronymic, A[i].phone, A[i].phone2);
    }
    
    return 0;
}
