	//Danh sach lien ket da thuc
	#include <stdio.h>
	#include <math.h>
	
	typedef struct dathuc
	{
	    int c, n;
	} dathuc;
	
	typedef struct Node
	{
	    dathuc Info;
	    Node* pNext;
	} Node;
	
	typedef struct List
	{
	    Node* pHead;
	    Node* pTail;
	} List;
	
	//Khai bao ham
	void Init(List &l);
	Node* GetNode(dathuc x);
	void AddTail(List &l, Node *new_ele);
	void InputTail(List &l);
	void Output(List l);
	void Output2(List l);
	void RemoveAfter(List &l, Node *q);
	long Valua(List l, int x);
	void Reduce(List &l);
	
	int main()
	{
	    List ds;
	    int x;
	
	    //Khoi tao danh sach
	    Init(ds);
	
	    //Nhap da thuc
	    InputTail(ds);
	
	    //Xuat da thuc
	    Output2(ds);
	
	    //Nhap x
	    printf("\nNhap x: ");
	    scanf("%d", &x);
	
	    //Tinh gia tri da thuc
	    printf("\nP(%d) = %ld", x, Valua(ds, x));
	
	    //Rut gon da thuc
	    Reduce(ds);
	
	    printf("\nDa thuc sau khi rut gon:");
	    Output2(ds);
	
	    return 0;
	}
	
	//Tao danh sach rong
	void Init(List &l)
	{
	    l.pHead = l.pTail = NULL;
	}
	
	//Tao node
	Node* GetNode(dathuc x)
	{
	    Node *p;
	
	    p = new Node;
	
	    if(p == NULL)
	    {
	        printf("Khong du bo nho!");
	        return NULL;
	    }
	
	    p->Info = x;
	    p->pNext = NULL;
	
	    return p;
	}
	
	//Them vao cuoi danh sach
	void AddTail(List &l, Node *new_ele)
	{
	    if(l.pHead == NULL)
	    {
	        l.pHead = new_ele;
	        l.pTail = l.pHead;
	    }
	    else
	    {
	        l.pTail->pNext = new_ele;
	        l.pTail = new_ele;
	    }
	}
	
	//Nhap da thuc
	void InputTail(List &l)
	{
	    int n;
	    dathuc x;
	
	    printf("Nhap so luong don thuc: ");
	    scanf("%d", &n);
	
	    for(int i = 1; i <= n; i++)
	    {
	        printf("\nNhap he so: ");
	        scanf("%d", &x.c);
	
	        printf("Nhap so mu: ");
	        scanf("%d", &x.n);
	
	        Node* p = GetNode(x);
	
	        AddTail(l, p);
	    }
	}
	
	//In danh sach
	void Output(List l)
	{
	    Node* p = l.pHead;
	
	    while(p != NULL)
	    {
	        printf("\n%dx^%d", p->Info.c, p->Info.n);
	
	        p = p->pNext;
	    }
	}
	
	//In da thuc theo dang P(x)
	void Output2(List l)
	{
	    Node* p = l.pHead;
	
	    printf("\nP(x) = ");
	
	    while(p != NULL)
	    {
	        printf("%dx^%d", p->Info.c, p->Info.n);
	
	        if(p->pNext != NULL)
	        {
	            printf(" + ");
	        }
	
	        p = p->pNext;
	    }
	}
	
	//Xoa node sau q
	void RemoveAfter(List &l, Node *q)
	{
	    if((q != NULL) && (q->pNext != NULL))
	    {
	        Node* p = q->pNext;
	
	        q->pNext = p->pNext;
	
	        if(p == l.pTail)
	        {
	            l.pTail = q;
	        }
	
	        delete p;
	    }
	}
	
	//Tinh gia tri da thuc
	long Valua(List l, int x)
	{
	    Node* p = l.pHead;
	
	    long px = 0;
	
	    while(p != NULL)
	    {
	        px = px + p->Info.c * pow(x, p->Info.n);
	
	        p = p->pNext;
	    }
	
	    return px;
	}
	
	//Rut gon da thuc
	void Reduce(List &l)
	{
	    Node *q1, *p = l.pHead;
	
	    while(p != NULL)
	    {
	        q1 = p;
	
	        while(q1->pNext != NULL)
	        {
	            if(q1->pNext->Info.n == p->Info.n)
	            {
	                p->Info.c =
	                p->Info.c + q1->pNext->Info.c;
	
	                RemoveAfter(l, q1);
	            }
	            else
	            {
	                q1 = q1->pNext;
	            }
	        }
	
	        p = p->pNext;
	    }
	}