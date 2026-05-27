	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	typedef struct node
	{
	    char Info;
	    struct node* pNext;
	} node;
	
	typedef struct Stack
	{
	    node* top;
	} stack;
	
	typedef struct Queue
	{
	    node* pHead;
	    node* pTail;
	} queue;
	
	/* khai bao ham stack */
	void InitStack(stack *s);
	int EmptyStack(stack s);
	void Push(stack *s, char x);
	char Pop(stack *s);
	
	/* khai bao ham queue */
	void InitQueue(queue *q);
	int EmptyQueue(queue q);
	void EnQueue(queue *q, char x);
	char DeQueue(queue *q);
	void PrintQueue(queue q);
	
	int main()
	{
	    stack ss;
	    queue qq;
	    char data[100];
	
	    InitStack(&ss);
	    InitQueue(&qq);
	
	    scanf("%s", data);
	
	    for (int i = 0; i < strlen(data); i++)
	    {
	        if (data[i] == '*')
	        {
	            printf("%c", Pop(&ss));
	        }
	        else
	        {
	            Push(&ss, data[i]);
	            EnQueue(&qq, data[i]);
	        }
	    }
	
	    printf("\nQueue: ");
	    PrintQueue(qq);
	
	    return 0;
	}
	
	/* STACK */
	void InitStack(stack *s)
	{
	    s->top = NULL;
	}
	
	int EmptyStack(stack s)
	{
	    return s.top == NULL;
	}
	
	void Push(stack *s, char x)
	{
	    node *p = (node*)malloc(sizeof(node));
	    p->Info = x;
	    p->pNext = s->top;
	    s->top = p;
	}
	
	char Pop(stack *s)
	{
	    if (!EmptyStack(*s))
	    {
	        node *p = s->top;
	        char x = p->Info;
	        s->top = p->pNext;
	        free(p);
	        return x;
	    }
	    return '\0';
	}
	
	/* QUEUE */
	void InitQueue(queue *q)
	{
	    q->pHead = q->pTail = NULL;
	}
	
	int EmptyQueue(queue q)
	{
	    return q.pHead == NULL;
	}
	
	void EnQueue(queue *q, char x)
	{
	    node *p = (node*)malloc(sizeof(node));
	    p->Info = x;
	    p->pNext = NULL;
	
	    if (q->pHead == NULL)
	    {
	        q->pHead = q->pTail = p;
	    }
	    else
	    {
	        q->pTail->pNext = p;
	        q->pTail = p;
	    }
	}
	
	char DeQueue(queue *q)
	{
	    if (!EmptyQueue(*q))
	    {
	        node *p = q->pHead;
	        char x = p->Info;
	        q->pHead = p->pNext;
	        free(p);
	        return x;
	    }
	    return '\0';
	}
	
	void PrintQueue(queue q)
	{
	    node *p = q.pHead;
	    while (p != NULL)
	    {
	        printf("%c ", p->Info);
	        p = p->pNext;
	    }
	    printf("\n");
	}
