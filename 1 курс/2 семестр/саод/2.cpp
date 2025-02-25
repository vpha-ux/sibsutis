#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#define N 100
#define NN 200
#define NNN 300
#define NNNN 400
#define NNNNN 500
#define NNNNNN 600
#define NNNNNNN 700

int A1[N];
int A2[NN];
int A3[NNN];
int A4[NNNN];
int A5[NNNNN];

int A6[NNNNNN];
int A7[NNNNNNN];

void FillInc(int A[], int n) 
{ 
    for (int i = 0; i < n; i++) 
    { 
        A[i] += i; 
    } 
} 
 
void FillDec(int A[], int n) 
{ 
    for (int i = 0; i < n; i++) 
    { 
        A[i] = 10-i; 
    } 
} 
 
void FillRand(int A[], int n) 
{ 
    
    for( int i = 0; i < n; i++) 
    { 
        A[i] = rand ()%10; 
     
    } 
} 


int BubbleSort(int A[], int n)
{
    int temp;
    int C = 0; 
    int M = 0;
    for (int i = 0; i < n-1; i++ )
    {
        for (int j = n-1; j > i; j-- )
        {
            C++;
            
            if (A[j] < A[j-1]) 
            {
                temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                M +=3;
            }
        }
    }
    return M+C;
}
 
int CM (int n)
{
    int M, C;
    C = (n*n - n)/2;
    M = 3*(n*n - n)/4;
    return M+C;
}

void Table(int N1, int N2, int N3, int N4, int N5, int D1, int D2, int D3, int D4, int D5, int R1, int R2, int R3, int R4, int R5, int I1, int I2, int I3, int I4, int I5){
    printf("\n");    printf("N   !   T    !              F             !\n");
    printf("-------------------------------------------- \n");
    printf("    !        !FillDec ! FillRand  ! FillInc!\n");    
    printf("-------------------------------------------- \n");
    printf("100 ! %.5d  ! %.5d  ! %.5d     ! %.4d   !\n", N1, D1, R1, I1);
    printf("\n");
    printf("200 ! %.5d  ! %.5d  ! %.5d     ! %.5d  !\n", N2, D2, R2, I2);
    printf("\n");
    printf("300 ! %.6d ! %.6d ! %.6d    ! %.5d  !\n", N3, D3, R3, I3);
    printf("\n");
    printf("400 ! %.6d ! %.6d ! %.6d    ! %.5d  !\n", N4, D4, R4, I4);  
    printf("\n");
    printf("500 ! %.6d ! %.6d ! %.6d    ! %.6d !\n ", N5, D5, R5, I5);
}

int main(){
    
    FillInc(A1, N);
    FillInc(A2, NN);
    FillInc(A3, NNN);
    FillInc(A4, NNNN);
    FillInc(A5, NNNNN);
    
    int I1 = BubbleSort(A1, N);
    int I2 = BubbleSort(A2, NN);
    int I3 = BubbleSort(A3, NNN);
    int I4 = BubbleSort(A4, NNNN);
    int I5 = BubbleSort(A5, NNNNN);
    
    FillDec(A1, N);
    FillDec(A2, NN);
    FillDec(A3, NNN);
    FillDec(A4, NNNN);
    FillDec(A5, NNNNN);
    
    int D1 = BubbleSort(A1,N);
    int D2 = BubbleSort(A2, NN);
    int D3 = BubbleSort(A3, NNN);
    int D4 = BubbleSort(A4, NNNN);
    int D5 = BubbleSort(A5, NNNNN);
    
    FillDec(A1, N);
    FillDec(A2, NN);
    FillDec(A3, NNN);
    FillDec(A4, NNNN);
    FillDec(A5, NNNNN);FillRand(A1, N);
    FillRand(A2, NN);
    FillRand(A3, NNN);
    FillRand(A4, NNNN);
    FillRand(A5, NNNNN);
    
    int R1 = BubbleSort(A1,N);
    int R2 = BubbleSort(A2, NN);
    int R3 = BubbleSort(A3, NNN);
    int R4 = BubbleSort(A4, NNNN);
    int R5 = BubbleSort(A5, NNNNN);
    
    int N1 = CM(N);
    int N2 = CM(NN);
    int N3 = CM(NNN);
    int N4 = CM(NNNN);
    int N5 = CM(NNNNN);
    
    Table(N1, N2, N3, N4, N5, D1, D2, D3, D4, D5, R1, R2, R3, R4, R5, I1, I2, I3, I4, I5);
 
}
