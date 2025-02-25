#include <stdio.h>
#include <string.h>


struct abonents 
{
    char name[20];
    char surname[20];
    char patronymic[20];
    int age;
};

int less(struct abonents x, struct abonents y) 
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
    else 
    {
        return 0;
    }
}

int less2(struct abonents x, struct abonents y)
{
    if (strcmp(x.surname, y.surname) < 0) 
    {
        return 1;
    }
    else if (strcmp(x.surname, y.surname) > 0) 
    {
        return 0;
    }
    else if (strcmp(x.name, y.name) < 0) 
    {
        return 1;
    }
    else 
    {
        return 0;
    }
    
}

void InsertSort(struct abonents phoneBook[], int index[]) 
{
    int i, j;
    struct abonents temp;
    int key;

    for (i = 1; i < 4; i++) 
    {
        key = index[i]; 
        j = i - 1;

        while (j >= 0 && less(phoneBook[key], phoneBook[index[j]])) 
        {
            index[j + 1] = index[j];
            j = j - 1;
        }
        index[j + 1] = key; 
    }
}

void InsertSort2(struct abonents phoneBook[], int index[]) 
{
    int i, j;
    struct abonents temp;
    int key;

    for (i = 1; i < 4; i++) 
    {
        key = index[i]; 
        j = i - 1;

        while (j >= 0 && less2(phoneBook[key], phoneBook[index[j]])) 
        {
            index[j + 1] = index[j];
            j = j - 1;
        }
        index[j + 1] = key; 
    }
}


int main() 
{
    struct abonents phoneBook[] = 
    {
        {"Hovalyg", "Krictina", "Igorevna", 18},
        {"Sergeeva", "Victoria", "Igorevna", 20},
        {"Shagalieva", "Anastasia", "Alekseevna", 16},
        {"Speshilova", "Valeria", "Dmitrievna", 23}
    };


    int A[4];
    int B[4];
    
    for (int i = 0; i < 4; i++) 
    {
        A[i] = i;
        B[i] = i;
    }

    printf("Справочник до сортировки:\n");
    for (int i = 0; i < 4; i++) 
    {
        printf("%s %s %s %d\n", phoneBook[i].name, phoneBook[i].surname, phoneBook[i].patronymic, phoneBook[i].age);
    }

    InsertSort(phoneBook, A);
    InsertSort2(phoneBook, B);

    printf("\nСправочник отсортированный по имени:\n");
    for (int i = 0; i < 4; i++) 
    {
        printf("%s %s %s %d\n", phoneBook[A[i]].name, phoneBook[A[i]].surname, phoneBook[A[i]].patronymic, phoneBook[A[i]].age);
    }
    
    printf("\nСправочник отсортированный по фамилии:\n");
    for (int i = 0; i < 4; i++) 
    {
        printf("%s %s %s %d\n", phoneBook[B[i]].name, phoneBook[B[i]].surname, phoneBook[B[i]].patronymic, phoneBook[B[i]].age);
    }

    return 0;
}
