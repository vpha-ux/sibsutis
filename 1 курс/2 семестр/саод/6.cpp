#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <math.h>

#define N 100
#define NN 200
#define NNN 300
#define NNNN 400
#define NNNNN 500
#define NNNNNN 600
#define NNNNNNN 700
#define NNNNNNNN 800
#define NNNNNNNNN 900
#define NNNNNNNNNN 1000


int m1[N];
int m2[NN];
int m3[NNN];
int m4[NNNN];
int m5[NNNNN];
int m6[NNNNNN];
int m7[NNNNNNN];
int m8[NNNNNNNN];
int m9[NNNNNNNNN];
int m10[NNNNNNNNN];


void FILLInc(int m[], int n)
{
    for (int i=0; i<n; i++ )
    {
        m[i]+=i;
    }
}

void FILLDec(int m[], int n)
{
    for (int i=0; i<n; i++)
    {
        m[i]= (n - i);
    }
}

void FILLRand(int m[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        m[i] = rand() % n;
  }
}

int ShakerSort(int m[], int n)
{
    int M = 0, C = 0, tmp = 0, L = 0, R = n - 1, k = n - 1;
    do
    {
        for (int j = R; j > L; j--)
        {
            C++; if (m[j] < m[j -1])
            {
                tmp = m[j];
                m[j] = m[j-1];
                m[j-1] = tmp;
                k = j;
                M+=3;
            }
        }
        L = k;
        for (int j = L; j < R; j++)
        {
            C++; if (m[j] > m[j+1])
            {
                tmp = m[j];
                m[j] = m[j+1];
                m[j+1] = tmp;
                k = j; 
                M+=3;
            }
        }
        R = k;
    } while (L < R);
}

int BinarySearch1(int m[], int n)
{
    int M = 0, C = 0, L = 0, R = n, X = 5, nn = 0;
    while(L<=R){
        int mm = (L+R)/2;
        C++; if (m[mm] = X){
            nn = 1;
        }
        C++; 
        if (m[mm] < X) L = mm+1;
        else R = mm -1;
    }
    if (nn == 1) return C;
    else printf("Error");
}


int BinarySearch2(int m[], int n)
{
    int M = 0, C = 0, L = 0, R = n, X = 5, nn = 0;
    while(L<R){
        int mm = (L+R)/2;
        C++; 
        if (m[mm] < X) L = mm+1;
        else R = mm;
    }
    C++; 
    if (m[R] = X) return C;
    else printf("Error");
    
}
void PrintMas(int m[], int n)
{
    for (int i=0; i<n; i++ )
    {
        printf("%d ", m[i]);
    }
}


void Table(int N1, int N2, int N3, int N4, int N5, int D1, int D2, int D3, int D4, int D5, int N10, int N9, int N8, int N7, int N6, int D10, int D9, int D8, int D7, int D6){
    
    printf("  N  |   Сф I  |  Сф II  |\n");
    printf("-----------------------------------\n");
    printf("100  | %7d | %7d |\n", D1,N1);
    printf("200  | %7d | %7d |\n", D2,N2);    
    printf("300  | %7d | %7d |\n", D3,N3);
    printf("400  | %7d | %7d |\n", D4,N4);    
    printf("500  | %7d | %7d |\n", D5,N5);
    printf("600  | %7d | %7d |\n", D6,N6);
    printf("700  | %7d | %7d |\n", D7,N7);    
    printf("800  | %7d | %7d |\n", D8,N8);
    printf("900  | %7d | %7d |\n", D9,N9);    
    printf("1000 | %7d | %7d |\n", D10,N10);
}
int main(){
    
    FILLRand(m1, N);
    ShakerSort(m1, N);
    //PrintMas(m1, N);
    //printf("\n");
    FILLRand(m2, NN);
    ShakerSort(m2, NN);
    FILLRand(m3, NNN);
    ShakerSort(m3, NNN);
    FILLRand(m4, NNNN);
    ShakerSort(m4, NNNN);
    FILLRand(m5, NNNNN);
    ShakerSort(m5, NNNNN);
    FILLRand(m6, NNNNNN);
    ShakerSort(m6, NNNNNN);
    FILLRand(m7, NNNNNNN);
    ShakerSort(m7, NNNNNNN);
    FILLRand(m8, NNNNNNNN);
    ShakerSort(m8, NNNNNNNN);
    FILLRand(m9, NNNNNNNNN);
    ShakerSort(m9, NNNNNNNNN);
    FILLRand(m10, NNNNNNNNN);
    ShakerSort(m10, NNNNNNNNN);
    int D1 = BinarySearch1(m1,N), D2 = BinarySearch1(m2, NN), D3 = BinarySearch1(m3, NNN), D4 = BinarySearch1(m4, NNNN), D5 = BinarySearch1(m5, NNNNN), D6 = BinarySearch1(m6, NNNNNN), D7 = BinarySearch1(m7, NNNNNNN), D8 = BinarySearch1(m8, NNNNNNNN), D9 = BinarySearch1(m9, NNNNNNNNN), D10 = BinarySearch1(m10, NNNNNNNNNN);
    
    FILLRand(m1, N);
    ShakerSort(m1, N);
    //PrintMas(m1, N);
    //printf("\n");
    FILLRand(m2, NN);
    ShakerSort(m2, NN);
    FILLRand(m3, NNN);
    ShakerSort(m3, NNN);
    FILLRand(m4, NNNN);
    ShakerSort(m4, NNNN);
    FILLRand(m5, NNNNN);
    ShakerSort(m5, NNNNN);
    FILLRand(m6, NNNNNN);
    ShakerSort(m6, NNNNNN);
    FILLRand(m7, NNNNNNN);
    ShakerSort(m7, NNNNNNN);
    FILLRand(m8, NNNNNNNN);
    ShakerSort(m8, NNNNNNNN);
    FILLRand(m9, NNNNNNNNN);
    ShakerSort(m9, NNNNNNNNN);
    FILLRand(m10, NNNNNNNNN);
    ShakerSort(m10, NNNNNNNNN);
    int N1 = BinarySearch2(m1,N), N2 = BinarySearch2(m2, NN), N3 = BinarySearch2(m3, NNN), N4 = BinarySearch2(m4, NNNN), N5 = BinarySearch2(m5, NNNNN), N6 = BinarySearch2(m6, NNNNNN), N7 = BinarySearch2(m7, NNNNNNN), N8 = BinarySearch2(m8, NNNNNNNN), N9 = BinarySearch2(m9, NNNNNNNNN), N10 = BinarySearch2(m10, NNNNNNNNNN);
    
    Table(N1, N2, N3, N4, N5, D1, D2, D3, D4, D5, N10, N9, N8, N7, N6, D10, D9, D8, D7, D6);
}
