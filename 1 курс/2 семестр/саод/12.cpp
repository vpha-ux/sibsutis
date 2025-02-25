#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int M = 0, C = 0;
int n = 10;

struct tLE {
    tLE *next;
    int data;
};

struct queue {
    tLE *head;
    tLE *tail;
};

void StackFillInc(int n, tLE* (&head)) {
    int i = n;
    tLE* p = NULL;
    do {
        head = new tLE;
        head->next = p;
        p = head;
        head->data = i;
        i--;
    } while (i > 0);
}

void StackFillDec(int n, tLE* (&head)) {
    int i = 1;
    tLE* p = NULL;
    do {
        head = new tLE;
        head->next = p;
        p = head;
        head->data = i;
        i++;
    } while (i <= n);
}

void StackFillRand(int n, tLE* (&head)) {
    srand(time(NULL));
    int i = 1;
    tLE* p = NULL;
    do {
        head = new tLE;
        head->next = p;
        p = head;
        head->data = rand() % (n * 2 + 1); 
        i++;
    } while (i <= n);
}

void FillIncQueue(int n, struct queue** queue) {
    struct tLE** tail = &((*queue)->tail);
    struct tLE* p;
    for (int i = 1; i <= n; i++) {
        p = (struct tLE*)malloc(sizeof(struct tLE));
        p->data = i;
        (*tail)->next = p;
        *tail = p;
    }
    (*tail)->next = NULL;
}

void FillDecQueue(int n, struct queue** queue) {
    struct tLE** tail = &((*queue)->tail);
    struct tLE* p;
    for (int i = n; i > 0; i--) {
        p = (struct tLE*)malloc(sizeof(struct tLE));
        p->data = i;
        (*tail)->next = p;
        *tail = p;
    }
    (*tail)->next = NULL;
}

void FillRandQueue(int n, struct queue** queue) {
    struct tLE** tail = &((*queue)->tail);
    struct tLE* p;
    for (int i = n; i > 0; i--) {
        p = (struct tLE*)malloc(sizeof(struct tLE));
        p->data = rand() % (n * 2 + 1);
        (*tail)->next = p;
        *tail = p;
    }
    (*tail)->next = NULL;
}

int CheckSum(tLE* head) {
    tLE* p;
    int sum = 0;
    for (p = head; p; p = p->next) {
        sum += p->data;
    }
    return sum;
}

int RunNumber(tLE* head) {
    int sequence = 1;
    tLE* p;
    for (p = head; p->next; p = p->next) {
        if (p->data > p->next->data) {
            sequence++;
        }
    }
    return sequence;
}

void PrintList(tLE* head) {
    tLE* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void DeleteList(tLE*& head, tLE*& tail) {
    tLE* current = head;
    while (current != NULL) {
        tLE* temp = current;
        current = current->next;
        delete temp;
    }
    head = tail = NULL;
}

void StackToQueue(struct tLE** head, struct tLE** tail) {
    (*tail)->next = *head;
    *tail = *head;
    *head = (*head)->next;
    (*tail)->next = NULL;
}

void MergeSeries(tLE** head_a, tLE** head_b, tLE** tail, int q, int r) {
    while (q != 0 && r != 0) {
        C++;
        if ((*head_a)->data <= (*head_b)->data) {
            StackToQueue(head_a, tail);
            M++;
            q--;
        } else {
            StackToQueue(head_b, tail);
            M++;
            r--;
        }
    }
    while (q > 0) {
        StackToQueue(head_a, tail);
        M++;
        q--;
    }
    while (r > 0) {
        StackToQueue(head_b, tail);
        M++;
        r--;
    }
}

void Split(tLE** head, tLE** head_a, tLE** head_b) {
    tLE* k, * p;
    *head_a = *head;
    *head_b = (*head)->next;
    k = *head_a;
    p = *head_b;
    M += 4;
    while (p != NULL) {
        k->next = p->next;
        k = p;
        p = p->next;
        M += 2;
    }
}

void MergeSort(tLE** head, tLE** tail, int n) {
    int i, m, q, p = 1, r;
    tLE *a = NULL, *b = NULL;
    queue c[2];
    Split(head, &a, &b);
    while (p < n) {
        c[0].tail = (tLE*)&c[0].head;
        c[1].tail = (tLE*)&c[1].head;
        i = 0;
        m = n;
        while (m > 0) {
            if (m >= p) q = p;
            else q = m;
            m -= q;
            if (m >= p) r = p;
            else r = m; 
            m -= r;
            MergeSeries(&a, &b, &c[i].tail, q, r);
            i = 1 - i;
        }
        a = c[0].head;
        b = c[1].head;
        p *= 2;
    }
    c[0].tail->next = NULL;
    *head = c[0].head;
}

int main() {
    int w = 0;
    tLE *head = NULL, *tail = NULL;
    printf(" N      M + C     Dec    Rand    Inc   \n\n");
    for (n = 100; n < 501; n += 100) {
        printf("%d ", n);
        w = (ceil(log2(n)) * n) * 2 + n;
        printf("%8d   ", w);
        StackFillDec(n, head);
        MergeSort(&head, &tail, n);
        printf("%6d  ", M + C);
        M = 0; C = 0;
        DeleteList(head, tail);
        
        StackFillRand(n, head);
        MergeSort(&head, &tail, n);
        printf("%5d  ", M + C);
        M = 0; C = 0;
        DeleteList(head, tail);
        
        StackFillInc(n, head);
        MergeSort(&head, &tail, n);
        printf("%6d  ", M + C);
        M = 0; C = 0;
        DeleteList(head, tail);
        printf("\n\n");
    }
    
    n = 10;
    printf("\n\nSplit\n");
    struct tLE *head_main = NULL, *tail_main = NULL;
    struct tLE *head_a = NULL;
    struct tLE *head_b = NULL;
    
    StackFillInc(n, head_a);
    StackFillInc(n, head_b);
    StackFillRand(n, head_main);
    
    PrintList(head_main);
    Split(&head_main, &head_a, &head_b);
    PrintList(head_a);
    PrintList(head_b);
    printf("\n\n");
    
    printf("\n\nMerge Series\n");
    head_main = NULL;
    tail_main = (struct tLE *)&head_main;
    head_a = NULL;
    head_b = NULL;
    
    StackFillInc(n, head_a);
    PrintList(head_a);
    StackFillInc(n, head_b);
    PrintList(head_b);
    
    MergeSeries(&head_a, &head_b, &tail_main, n, n);
    PrintList(head_main);
    
    return 0;
}
