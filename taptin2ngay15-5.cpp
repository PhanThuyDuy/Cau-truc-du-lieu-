	#include <stdio.h>
	#include <string.h>
	
	// ================= KHAI BAO CAU TRUC =================
	
	typedef struct sinhvien
	{
	    char maso[10];
	    char hoten[40];
	    float dtb;
	
	} sinhvien;
	
	typedef struct Node
	{
	    sinhvien Info;
	    struct Node* pNext;
	
	} Node;
	
	typedef struct List
	{
	    Node* pHead;
	    Node* pTail;
	
	} List;
	
	// ================= KHAI BAO HAM =================
	
	void Init(List &l);
	
	Node* GetNode(sinhvien x);
	
	void AddFirst(List &l, Node* new_ele);
	
	void AddTail(List &l, Node *new_ele);
	
	void AddAfter(List &l,Node *q, Node* new_ele);
	
	void InputHead(List &l);
	
	void InputTail(List &l);

	void Output(List l);
	
	Node* Search1(List l, char x[]);

	void TimKiemSV(List l);
		
	void InDTBCao(List l);
	
	int DemRot(List l);
	

	// ================= CHUONG TRINH CHINH =================
	
	int main()
	{
	    List y;
	
	    Init(y);
	
	    InputHead(y);
	
	    printf("\nDANH SACH SINH VIEN \n");
	
	    Output(y);
	
	   
  	  	// Tim kiem theo dieu kien 
    	TimKiemSV(y);
	
	    // In theo dieu kien 
	
	    InDTBCao(y);
	
	    // Dem theo dieu kien 
	
	    printf("\nSo sinh vien rot (DTB < 5): %d", DemRot(y));
	
	    return 0;
	}
	
	// ================= KHOI TAO DANH SACH =================
	
	void Init(List &l)
	{
	    l.pHead = NULL;
	    l.pTail = NULL;
	}
	
	// ================= TAO NODE =================
	
	Node* GetNode(sinhvien x)
	{
	    Node* p = new Node;
	
	    if (p == NULL)
	    {
	        printf("Khong du bo nho!");
	        return NULL;
	    }
	
	    p->Info = x;
	
	    p->pNext = NULL;
	
	    return p;
	}
	
	// ================= THEM DAU =================
	
	void AddFirst(List &l, Node* new_ele)
	{
	    if (l.pHead == NULL)
	    {
	        l.pHead = l.pTail = new_ele;
	    }
	    else
	    {
	        new_ele->pNext = l.pHead;
	
	        l.pHead = new_ele;
	    }
	}
	
	// ================= THEM CUOI DANH SACH =================
		void AddTail(List &l, Node *new_ele)
	
	{
	
	if (l.pHead==NULL)
	
	{
	
	l.pHead = new_ele;
	
	l.pTail = l.pHead;
	
	}
	
	else
	
	{
	
	l.pTail->pNext = new_ele;
	
	l.pTail = new_ele ;
	
	}
	
	}
		
	


// ================= CHEN 1 PT SAU Q =================	
	
		void AddAfter(List &l,Node *q, Node* new_ele)
	
	{
	
	if (q!=NULL && new_ele !=NULL)
	
	{
	
	new_ele->pNext = q->pNext;
	
	q->pNext = new_ele;
	
	if(q == l.pTail)
	
	l.pTail = new_ele;
	
	}
	
	else
	
	AddFirst(l,new_ele);
	
	}
		
	







	// ================= NHAP N DU LIEU VAO DAU DANH SACH =================
	
	void InputHead(List &l)
	{
	    int n;
	
	    sinhvien x;
	
	    printf("Nhap so sinh vien: ");
	    scanf("%d", &n);
	
	    getchar();
	
	    for (int i = 1; i <= n; i++)
	    {
	        printf("\nNhap sinh vien thu %d\n", i);
	
	        printf("Nhap ma so: ");
	        gets(x.maso);
	 		fflush(stdin); 
	        
			printf("Nhap ho ten: ");
	        gets(x.hoten);
	        fflush(stdin); 
	        
			printf("Nhap diem trung binh: ");
	        scanf("%2.f", &x.dtb);
	
	        getchar();
	
	        Node* p = GetNode(x);
	
	        AddFirst(l, p);
	    }
	}
	
	// ================= NHAP N DU LIEU VAO CUOI DANH SACH =================
	
	
	void InputTail(List &l)
	
	{
	int n;
	
	sinhvien x;
	
	printf("Nhap so pt: ");
	scanf("%d",&n);
	
	 getchar();
	
	    for (int i = 1; i <= n; i++)
	    {
	        printf("\nNhap sinh vien thu %d\n", i);
	
	        printf("Nhap ma so: ");
	        gets(x.maso);
	 		fflush(stdin); 
	       
		    printf("Nhap ho ten: ");
	        gets(x.hoten);
			 fflush(stdin); 
	      
		    printf("Nhap diem trung binh: ");
	        scanf("%f", &x.dtb);
	
	        getchar();
	
	        Node* p = GetNode(x);
	
	AddTail(l, p);
	
	}
	
	}
	




	// ================= XUAT DANH SACH =================
	
	void Output(List l)
	{
	    Node* p = l.pHead;
	
	    while (p != NULL)
	    {
	        printf("\nMa so : %s", p->Info.maso);
	
	        printf("\nHo ten: %s", p->Info.hoten);
	
	        printf("\nDTB   : %.2f\n", p->Info.dtb);
	
	        printf("-------------------------\n");
	
	        p = p->pNext;
	    }
	}
	
	// ================= TIM KIEM MSSV =================
	
	Node* Search1(List l, char x[])
	{
	    Node* p = l.pHead;
	
	    while (p != NULL)
	    {
	        if (strcmp(p->Info.maso, x) == 0)
	        {
	            return p;
	        }
	
	        p = p->pNext;
	    }
	
	    return NULL;
	}
	
	

		 void TimKiemSV(List l) // in ra tim kiem 
	{
	    char ms[10];
	
	    getchar(); 
	
	    printf("\nNhap ma so can tim: ");
	    gets(ms);
	
	    Node* kq = Search1(l, ms);
	
	    if (kq != NULL)
	    {
	        printf("\nTIM THAY SINH VIEN\n");
	
	        printf("Ma so : %s\n", kq->Info.maso);
	        printf("Ho ten: %s\n", kq->Info.hoten);
	        printf("DTB   : %.2f\n", kq->Info.dtb);
	    }
	    else
	    {
	        printf("\nKhong tim thay sinh vien!");
	    }
	}
		
	
	
	
	
	
	
	
	
	
	
	
	
	// ================= IN DTB >= 8 =================
	
void InDTBCao(List l)
{
    Node* p = l.pHead;

    int found = 0;

    printf("\n SINH VIEN CO DTB >= 8 \n");

    while (p != NULL)
    {
        if (p->Info.dtb >= 8)
        {
            found = 1;

            printf("Ma so : %s\n", p->Info.maso);

            printf("Ho ten: %s\n", p->Info.hoten);

            printf("DTB   : %.2f\n", p->Info.dtb);

            printf("----------------------\n");
        }

        p = p->pNext;
    }

    if (found == 0)
    {
        printf("Khong co sinh vien nao co DTB >= 8\n");
    }
}

	// ================= DEM DTB < 5 =================
	
	int DemRot(List l)
	{
	    int dem = 0;
	
	    Node* p = l.pHead;
	
	    while (p != NULL)
	    {
	        if (p->Info.dtb < 5)
	        {
	            dem++;
	        }
	
	        p = p->pNext;
	    }
	
	    return dem;
	}
