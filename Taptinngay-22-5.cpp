#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Data
{
    int MaSo;
    char CPU[50];
    int RAM;
    int SSD;

} Data;

typedef struct DNode
{
    Data Info;

    DNode* pPrev;
    DNode* pNext;

} DNode;

typedef struct DList
{
    DNode* pHead;
    DNode* pTail;

} DList;


// ================= KHAI BAO HAM =================

void Init(DList &l);

DNode* GetNode(Data x);

void AddFirst(DList &l, DNode* new_ele);

void AddTail(DList &l, DNode* new_ele);

void InputHead(DList &l);

void InputTail(DList &l);

void OutputHeadToTail(DList l);

void OutputTailToHead(DList l);


// ================= MAIN =================

int main()
{
    DList l;

    Init(l);

  
    printf("===== NHAP VAO DAU DANH SACH =====\n");
    InputHead(l);

  //  printf("\n===== NHAP VAO CUOI DANH SACH =====\n");
  //  InputTail(l);

    printf("\n===== DANH SACH TU DAU DEN CUOI =====\n");
    OutputHeadToTail(l);

    printf("\n===== DANH SACH TU CUOI VE DAU =====\n");
    OutputTailToHead(l);

    return 0;
}


// ================= DINH NGHIA HAM =================

	
	// Khoi tao danh sach rong
	void Init(DList &l)
	{
	    l.pHead = NULL;
	    l.pTail = NULL;
	}
	
	
	// Tao node moi
	DNode* GetNode(Data x)
	{
	    DNode* p = new DNode;
	
	    if (p == NULL)
	    {
	        printf("Khong du bo nho!\n");
	        exit(1);
	    }
	
	    p->Info = x;
	
	    p->pPrev = NULL;
	    p->pNext = NULL;
	
	    return p;
	}
	
	
	// Chen vao dau danh sach
	void AddFirst(DList &l, DNode* new_ele)
	{
	    if (l.pHead == NULL)
	    {
	        l.pHead = new_ele;
	        l.pTail = new_ele;
	    }
	    else
	    {
	        new_ele->pNext = l.pHead;
	
	        l.pHead->pPrev = new_ele;
	
	        l.pHead = new_ele;
	    }
	}
	
	
	// Chen vao cuoi danh sach
	void AddTail(DList &l, DNode* new_ele)
	{
	    if (l.pHead == NULL)
	    {
	        l.pHead = new_ele;
	        l.pTail = new_ele;
	    }
	    else
	    {
	        l.pTail->pNext = new_ele;
	
	        new_ele->pPrev = l.pTail;
	
	        l.pTail = new_ele;
	    }
	}
	
	
	// Nhap vao dau danh sach
	void InputHead(DList &l)
	{
	    int n;
	
	    printf("Nhap so luong may tinh: ");
	    scanf("%d", &n);
	
	    getchar();
	
	    for (int i = 1; i <= n; i++)
	    {
	        Data x;
	
	        printf("\nNhap may tinh thu %d\n", i);
	
	        printf("Nhap ma so: ");
	        scanf("%d", &x.MaSo);
	
	        getchar();
	
	        printf("Nhap loai CPU: ");
	        fgets(x.CPU, sizeof(x.CPU), stdin);
	        x.CPU[strcspn(x.CPU, "\n")] = '\0';
	
	        printf("Nhap dung luong RAM: ");
	        scanf("%d", &x.RAM);
	
	        printf("Nhap dung luong SSD: ");
	        scanf("%d", &x.SSD);
	
	        getchar();
	
	        DNode* p = GetNode(x);
	
	        AddFirst(l, p);
	    }
	}
	
	
	// Nhap vao cuoi danh sach
	void InputTail(DList &l)
	{
	    int n;
	
	    printf("Nhap so luong may tinh: ");
	    scanf("%d", &n);
	
	    getchar();
	
	    for (int i = 1; i <= n; i++)
	    {
	        Data x;
	
	        printf("\nNhap may tinh thu %d\n", i);
	
	        printf("Nhap ma so: ");
	        scanf("%d", &x.MaSo);
	
	        getchar();
	
	        printf("Nhap loai CPU: ");
	        fgets(x.CPU, sizeof(x.CPU), stdin);
	        x.CPU[strcspn(x.CPU, "\n")] = '\0';
	
	        printf("Nhap dung luong RAM: ");
	        scanf("%d", &x.RAM);
	
	        printf("Nhap dung luong SSD: ");
	        scanf("%d", &x.SSD);
	
	        getchar();
	
	        DNode* p = GetNode(x);
	
	        AddTail(l, p);
	    }
	}
	
	
	// Xuat tu dau den cuoi
	void OutputHeadToTail(DList l)
	{
	    DNode* p = l.pHead;
	
	    while (p != NULL)
	    {
	        printf("Ma so: %d\n", p->Info.MaSo);
	
	        printf("CPU: %s\n", p->Info.CPU);
	
	        printf("RAM: %d GB\n", p->Info.RAM);
	
	        printf("SSD: %d GB\n", p->Info.SSD);
	
	        printf("--------------------------\n");
	
	        p = p->pNext;
	    }
	}
	
	
	// Xuat tu cuoi ve dau
	void OutputTailToHead(DList l)
	{
	    DNode* p = l.pTail;
	
	    while (p != NULL)
	    {
	        printf("Ma so: %d\n", p->Info.MaSo);
	
	        printf("CPU: %s\n", p->Info.CPU);
	
	        printf("RAM: %d GB\n", p->Info.RAM);
	
	        printf("SSD: %d GB\n", p->Info.SSD);
	
	        printf("--------------------------\n");
	
	        p = p->pPrev;
	    }
	}
