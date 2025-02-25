#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
typedef int Data;
Data A[N];

void FILLInc()
{
    for (Data i = 0; i < N; i++)
    {
        A[i] = i; 
    }
}

void FILLDec()
{
    for (Data i = 0; i < N; i++)
    {
        A[i] = (N - i);
    }
}

void FILLRand()
{
    srand(time(NULL));
    for (Data i = 0; i < N; i++)
    {
        A[i] = rand() % N; 
    }
}

void PrintMas()
{
    for (Data i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void RunNumber1()
{
    Data k = 0;
    for (Data i = 0; i < N - 1; i++) 
    {
        if (A[i] > A[i + 1])
        {
            k += 1;
        }
    }
    printf("Серии1 = %d; ", k);
}

void CheckSum1()
{
    Data count = 0;
    for (Data i = 0; i < N; i++)
    {
        count += A[i];
    }
    printf("КС1 = %d;\n", count);
}

typedef struct Node Node;

struct Node {
    Data data;
    Node* next;
};

void PrintHead(Node* head)
{
    printf("Стек: ");
    for (Node* p = head; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

void Push(Node** Phead, Data A[], Data n)
{
    for (Data i = 0; i < n; i++) 
    {
        Node* p = (Node*)malloc(sizeof(Node)); 
        p->data = A[i];
        p->next = *Phead;
        *Phead = p;
    }
}

void Delete(Node** Phead, Data n)
{
    Data i = 0;
    while (i < n && *Phead != NULL) 
    {
        Node* p = *Phead;
        *Phead = p->next;
        free(p);
        i++;
    }
}

void RunNumber2(Node** Phead)
{
    Data k = 0;
    Node* p = *Phead;

    while (p != NULL && p->next != NULL)
    {
        if (p->data > (p->next)->data)
        {
            k += 1;
        }
        p = p->next;
    }
    printf("Серии2 = %d; ", k);
}

void CheckSum2(Node** Phead)
{
    Data count = 0;
    Node* p = *Phead;
    while (p != NULL)
    {
        count += p->data;
        p = p->next;
    }
    printf("КС2 = %d;\n", count);
}

int main() {
    Node* head = NULL;

    //
    FILLInc();
    PrintMas();
    RunNumber1();
    CheckSum1();

    Push(&head, A, N);
    PrintHead(head);
    RunNumber2(&head);
    CheckSum2(&head);
    Delete(&head, N);
    printf("\n");

    //
    FILLDec();
    PrintMas();
    RunNumber1();
    CheckSum1();

    Push(&head, A, N);
    PrintHead(head);
    RunNumber2(&head);
    CheckSum2(&head);
    Delete(&head, N);
    printf("\n");

    //
    FILLRand();
    PrintMas();
    RunNumber1();
    CheckSum1();

    Push(&head, A, N);
    PrintHead(head);
    RunNumber2(&head);
    CheckSum2(&head);
    Delete(&head, N);
    printf("\n");

    return 0;
}
