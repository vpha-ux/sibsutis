#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <math.h>

#define N 100
#define NN 200
#define NNN 300
#define NNNN 400
#define NNNNN 500

int m1[N];
int m2[NN];
int m3[NNN];
int m4[NNNN];
int m5[NNNNN];

void FILLInc(int m[], int n) {
    for (int i = 0; i < n; i++) {
        m[i] += i;
    }
}

void FILLDec(int m[], int n) {
    for (int i = 0; i < n; i++) {
        m[i] = (n - i);
    }
}

void FILLRand(int m[], int n) {
    srand(time(NULL)); 
    for (int i = 0; i < n; i++) {
        m[i] = rand() % n; 
    }
}

int InsertSort(int m[], int n) {
    int M = 0, C = 0, tmp = 0;
    for (int i = 1; i < n; i++) { 
        int t = m[i];
        int j = i - 1;
        while (j >= 0 && (C++, t < m[j])) { 
            m[j + 1] = m[j];
            j = j - 1;
            M++;
        }
        m[j + 1] = t;
        M++;
    }
    return M + C;
}

int ShellSort(int m[], int n) {
    int M = 0, C = 0, k, temp;
    for (k = n / 2; k > 0; k /= 2) {
        for (int i = k; i < n; i++) {
            temp = m[i];
            M++;
            int j = i;

            while (j >= k && (C++, m[j - k] > temp)) { // Исправлено на C++
                m[j] = m[j - k];
                j -= k;
                M++;
            }
            m[j] = temp;
            M++;
        }
    }
    return M + C;
}

int KN(int n) {
    int m = log2(n) - 1;
    return m;
}

void Table(int N1, int N2, int N3, int N4, int N5, int D1, int D2, int D3, int D4, int D5, int IR1, int IR2, int IR3, int IR4, int IR5) {
    printf("    |  Knyt   |  Insert |   Shell |\n");
    printf("-----------------------------------\n");
    printf("100 | %7d | %7d | %7d |\n", D1, IR1, N1);
    printf("200 | %7d | %7d | %7d |\n", D2, IR2, N2);
    printf("300 | %7d | %7d | %7d |\n", D3, IR3, N3);
    printf("400 | %7d | %7d | %7d |\n", D4, IR4, N4);
    printf("500 | %7d | %7d | %7d |\n", D5, IR5, N5);
}

int main() {
    FILLRand(m1, N);
    FILLRand(m2, NN);
    FILLRand(m3, NNN);
    FILLRand(m4, NNNN);
    FILLRand(m5, NNNNN);
    int IR1 = InsertSort(m1, N), IR2 = InsertSort(m2, NN), IR3 = InsertSort(m3, NNN), IR4 = InsertSort(m4, NNNN), IR5 = InsertSort(m5, NNNNN);

    FILLRand(m1, N);
    FILLRand(m2, NN);
    FILLRand(m3, NNN);
    FILLRand(m4, NNNN);
    FILLRand(m5, NNNNN);
    int N1 = ShellSort(m1, N), N2 = ShellSort(m2, NN), N3 = ShellSort(m3, NNN), N4 = ShellSort(m4, NNNN), N5 = ShellSort(m5, NNNNN);

    int D1 = KN(N), D2 = KN(NN), D3 = KN(NNN), D4 = KN(NNNN), D5 = KN(NNNNN);

    Table(N1, N2, N3, N4, N5, D1, D2, D3, D4, D5, IR1, IR2, IR3, IR4, IR5);
    return 0;
}
