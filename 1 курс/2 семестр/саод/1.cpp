#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

//#define N 10;

int A[10]; 

void FillInc() 
{ 
    for (int i = 0; i < 10; i++) 
    { 
        A[i] += i; 
    } 
} 
 
void FillDec() 
{ 
    for (int i = 0; i < 10; i++) 
    { 
        A[i] = 10-i; 
    } 
} 
 
void FillRand() 
{ 
    
    for( int i = 0; i < 10; i++) 
    { 
        A[i] = rand ()%10; 
     
    } 
} 
 
void CheckSum() 
{ 
    int count = 0; 
    for(int i = 0; i < 10; i++) 
    { 
        count += A[i]; 
    } 
    printf("Kонтрольная сумма: %d ", count); 
     
} 
void RunNumber() 
{ 
    int x = 1; 
    for(int i = 0; i < 9; i++) 
    { 
        if (A[i] > A[i+1]) 
        { 
            x+=1; 
        } 
    } 
    printf("Серии: %d ", x); 
} 

void SelectSort()
{
    int C = 0, M = 0;
    int k;
    int temp;
    
    for (int i = 0; i < 9; i++)
    {
        k = i;
        
        for (int j = i + 1; j < 10; j++)
        {   
            C++; 
            if (A[j] < A[k])
            {
                k = j;
            }
        }
        if (i != k){
            
        temp = A[i];
        A[i] = A[k];
        A[k] = temp;
        M+=3;
            
        }
    };
    printf("\nC = %d; M = %d\n", C, M);
}

void PrintMas() 
{ 
    for (int i = 0; i < 10; i++) 
    { 
        printf("%d ", A[i]); 
    } 
} 
 
 
int main() 
{ 
    printf("Массив по возрастанию: ");
    FillInc();
    PrintMas();
    printf("\n");
    
    RunNumber();
    CheckSum();
    printf("\n");
    
    SelectSort();
    printf("Отсортированный массив SelectSort: ");
    
    PrintMas();
    printf("\n");
    
    RunNumber();
    CheckSum();
    printf("\n");
    printf("\n");
    
    printf("Массив по убыванию: ");
    FillDec();
    PrintMas();
    printf("\n");
    
    RunNumber();
    CheckSum();
    printf("\n");
    
    SelectSort();
    printf("Отсортированный массив SelectSort: ");
    
    PrintMas();
    printf("\n");
    
    RunNumber();
    CheckSum();
    printf("\n");
    printf("\n");
    
    printf("Массив случайных чисел: ");
    FillRand();
    PrintMas();
    printf("\n");
    
    RunNumber();
    CheckSum();
    printf("\n");
    
    SelectSort();
    printf("Отсортированный массив SelectSort: ");
    printf("\n");

    PrintMas();
    printf("\n");
    
    RunNumber();
    CheckSum();
    printf("\n");
    printf("\n");
    
    
 
}