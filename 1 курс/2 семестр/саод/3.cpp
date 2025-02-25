#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#define N 100
#define NN 200
#define NNN 300
#define NNNN 400
#define NNNNN 500


int A1[N];
int A2[NN];
int A3[NNN];
int A4[NNNN];
int A5[NNNNN];

int FillInc(int A[], int n) 
{ 
    for (int i = 0; i < n; i++) 
    { 
        A[i] += i; 
    } 
} 
 
int FillDec(int A[], int n) 
{ 
    for (int i = 0; i < n; i++) 
    { 
        A[i] = 10-i; 
    } 
} 
 
int FillRand(int A[], int n) 
{ 
    
    for( int i = 0; i < n; i++) 
    { 
        A[i] = rand ()% (n*2); 
     
    } 
} 


int BubbleSort(int A[], int n)
{
    int temp;
    int C = 0; 
    int M = 0;
    for (int i = 0; i < n - 1; i ++ )
    {
        for (int j = n - 1; j > i; j -- )
        {
            C++;
            
            if (A[j] < A[j-1]) 
            {
                temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
                M += 3;
            }
        }
    }
    return M+C;
}

int ShakerSort (int A[], int n)
{   
    int temp;
    int M = 0, C = 0;
    int L = 0, R =  n- 1, k = n - 1;
    
    do
    {
        for(int j = R; j > L; j --)
        { 
            C++;
            if(A[j] < A[j-1])
            {
                k = j;
                
                temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
                
                M += 3; 
                
            }
        }
        
        L = k;

        for(int j = L; j < R; j++) 
        { 
            C++;
            if(A[j] > A[j + 1]) 
            {
                k = j;
                
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                
                M += 3; 
                
            }
        }
        
        R = k;
    }
    while (L < R);
    
    return M+C;
    
}
 
int CM (int n)
{
    int M, C;
    C = (n*n - n)/2;
    M = 3*(n*n - n)/4;
    return M+C;
}

int PrintMas(int A[]) 
{ 
    for (int i = 0; i < 500; i++) 
    { 
        printf("%d ", A[i]); 
    } 
} 

void Table(int D1, int D2, int D3, int D4, int D5, int R1, int R2, int R3, int R4, int R5, int I1, int I2, int I3, int I4, int I5, int U1, int U2, int U3, int U4, int U5, int Y1, int Y2, int Y3, int Y4, int Y5, int E1, int E2, int E3, int E4, int E5  )
{   
    printf("--------------------------------------------------------------------------- \n");
    printf("N   !  F       BubbleSort          !       !     F ShakerSort             !\n");
    printf("--------------------------------------------------------------------------- \n");
    printf("    ! FillDec ! FillRand  ! FillInc!       ! FillInc ! FillRand  ! FillDec!\n");    
    printf("--------------------------------------------------------------------------- \n");
    printf("100 !  %.5d  ! %.5d     ! %.4d   !       ! %.5d   !   %.5d   !  %.5d ! \n", D1, R1, I1, U1, Y1, E1);
    printf("--------------------------------------------------------------------------- \n");
    printf("200 !  %.5d  ! %.5d     ! %.5d  !       ! %.5d   !   %.5d   !  %.5d ! \n",D2, R2, I2, U2, Y2, E2);
    printf("--------------------------------------------------------------------------- \n");
    printf("300 !  %.6d ! %.6d    ! %.5d  !       ! %.5d   !   %.5d   ! %.6d ! \n",D3, R3, I3, U3, Y3, E3);
    printf("--------------------------------------------------------------------------- \n");
    printf("400 !  %.6d ! %.6d    ! %.5d  !       ! %.5d   !   %.5d   ! %.6d ! \n",D4, R4, I4, U4, Y4, E4);  
    printf("--------------------------------------------------------------------------- \n");
    printf("500 !  %.6d ! %.6d    ! %.6d !       ! %.5d   !   %.5d   ! %.6d ! \n ",D5, R5, I5, U5, Y5, E5);
    printf("--------------------------------------------------------------------------- \n");
}int main(){
    
    /* для BubbleSort 
     I,D,R */
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
    
    FillRand(A1, N);
    FillRand(A2, NN);
    FillRand(A3, NNN);
    FillRand(A4, NNNN);
    FillRand(A5, NNNNN);
    
    int R1 = BubbleSort(A1,N);
    int R2 = BubbleSort(A2, NN);
    int R3 = BubbleSort(A3, NNN);
    int R4 = BubbleSort(A4, NNNN);
    int R5 = BubbleSort(A5, NNNNN);
    
    /*int N1 = CM(N);
    int N2 = CM(NN);
    int N3 = CM(NNN);
    int N4 = CM(NNNN);
    int N5 = CM(NNNNN);*/
    
    /* для ShakerSort
    U,Y,E */
    
        
    FillInc(A1, N);
    FillInc(A2, NN);
    FillInc(A3, NNN);
    FillInc(A4, NNNN);
    FillInc(A5, NNNNN);
    
    int U1 = ShakerSort(A1, N);
    int U2 = ShakerSort(A2, NN);
    int U3 = ShakerSort(A3, NNN);
    int U4 = ShakerSort(A4, NNNN);
    int U5 = ShakerSort(A5, NNNNN);
    
    FillDec(A1, N);
    FillDec(A2, NN);
    FillDec(A3, NNN);
    FillDec(A4, NNNN);
    FillDec(A5, NNNNN);
    
    int Y1 = ShakerSort(A1, N);
    int Y2 = ShakerSort(A2, NN);
    int Y3 = ShakerSort(A3, NNN);
    int Y4 = ShakerSort(A4, NNNN);
    int Y5 = ShakerSort(A5, NNNNN);
    
    FillRand(A1, N);
    FillRand(A2, NN);
    FillRand(A3, NNN);
    FillRand(A4, NNNN);
    FillRand(A5, NNNNN);
    
    
    int E1 = ShakerSort(A1, N);
    int E2 = ShakerSort(A2, NN);
    int E3 = ShakerSort(A3, NNN);
    int E4 = ShakerSort(A4, NNNN);
    int E5 = ShakerSort(A5, NNNNN);
    
    /*int N1 = CM(N);
    int N2 = CM(NN);
    int N3 = CM(NNN);
    int N4 = CM(NNNN);
    int N5 = CM(NNNNN);*/
    
   
   Table(D1, D2, D3, D4, D5, R1, R2, R3, R4, R5, I1, I2, I3, I4, I5, U1, U2, U3, U4, U5, Y1, Y2, Y3, Y4, Y5, E1, E2, E3, E4, E5);
 
}