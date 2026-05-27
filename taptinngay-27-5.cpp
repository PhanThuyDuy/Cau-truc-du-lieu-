#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// NODE
typedef struct Node
{
    char Info;
    struct Node* pNext;
} Node;

// STACK
typedef struct Stack
{
    Node* pHead;
} Stack;

// QUEUE
typedef struct Queue
{
    Node* pHead;
    Node* pTail;
} Queue;

// KHAI BAO HAM STACK
void InitStack(Stack &S);

int IsEmptyStack(Stack S);

Node* GetNode(char x);

void Push(Stack &S, char x);

char Pop(Stack &S);

void OutputStack(Stack S);

// KHAI BAO HAM QUEUE
void InitQueue(Queue &Q);

int IsEmptyQueue(Queue Q);

void EnQueue(Queue &Q, char x);

char DeQueue(Queue &Q);

char Front(Queue Q);

void OutputQueue(Queue Q);

// ham chinh 
int main()
{
    Stack S;
    Queue Q;

    InitStack(S);
    InitQueue(Q);

    char str[100];

    char resultStack[100];
    int k1 = 0;

    char resultQueue[100];
    int k2 = 0;

    printf("Nhap chuoi thao tac: ");
    scanf("%s", str);

    // STACK
    printf("\n===== STACK =====\n");

    for(int i = 0; str[i] != '\0'; i++)
    {
        char c = str[i];

        if(c == '*')
        {
            char x = Pop(S);

            printf("Pop: %c\n", x);

            resultStack[k1] = x;
            k1++;
        }
        else
        {
            Push(S, c);

            printf("Push: %c\n", c);
        }

        printf("Stack: ");
        OutputStack(S);

        printf("\n");
    }

    resultStack[k1] = '\0';

    printf("\nKet qua STACK: %s\n", resultStack);

    // QUEUE
    printf("\n===== QUEUE =====\n");

    for(int i = 0; str[i] != '\0'; i++)
    {
        char c = str[i];

        if(c == '*')
        {
            char x = DeQueue(Q);

            printf("DeQueue: %c\n", x);

            resultQueue[k2] = x;
            k2++;
        }
        else
        {
            EnQueue(Q, c);

            printf("EnQueue: %c\n", c);
        }

        printf("Queue: ");
        OutputQueue(Q);

        printf("\n");
    }

    resultQueue[k2] = '\0';

    printf("\nKet qua QUEUE: %s\n", resultQueue);

    return 0;
}

// HAM CHUNG
Node* GetNode(char x)
{
    Node* p = new Node;

    if(p == NULL)
    {
        printf("Khong du bo nho!\n");
        return NULL;
    }

    p->Info = x;
    p->pNext = NULL;

    return p;
}

// STACK
void InitStack(Stack &S)
{
    S.pHead = NULL;
}

int IsEmptyStack(Stack S)
{
    return (S.pHead == NULL);
}

void Push(Stack &S, char x)
{
    Node* p = GetNode(x);

    if(p == NULL) return;

    p->pNext = S.pHead;

    S.pHead = p;
}

char Pop(Stack &S)
{
    if(IsEmptyStack(S))
    {
        return '\0';
    }

    Node* p = S.pHead;

    char x = p->Info;

    S.pHead = S.pHead->pNext;

    delete p;

    return x;
}

void OutputStack(Stack S)
{
    Node* p = S.pHead;

    while(p != NULL)
    {
        printf("%c ", p->Info);

        p = p->pNext;
    }

    printf("\n");
}

// QUEUE
void InitQueue(Queue &Q)
{
    Q.pHead = Q.pTail = NULL;
}

int IsEmptyQueue(Queue Q)
{
    return (Q.pHead == NULL);
}

void EnQueue(Queue &Q, char x)
{
    Node* p = GetNode(x);

    if(p == NULL) return;

    if(IsEmptyQueue(Q))
    {
        Q.pHead = Q.pTail = p;
    }
    else
    {
        Q.pTail->pNext = p;

        Q.pTail = p;
    }
}

char DeQueue(Queue &Q)
{
    if(IsEmptyQueue(Q))
    {
        return '\0';
    }

    Node* p = Q.pHead;

    char x = p->Info;

    Q.pHead = Q.pHead->pNext;

    if(Q.pHead == NULL)
    {
        Q.pTail = NULL;
    }

    delete p;

    return x;
}

char Front(Queue Q)
{
    if(IsEmptyQueue(Q))
    {
        return '\0';
    }

    return Q.pHead->Info;
}

void OutputQueue(Queue Q)
{
    Node* p = Q.pHead;

    while(p != NULL)
    {
        printf("%c ", p->Info);

        p = p->pNext;
    }

    printf("\n");
}
