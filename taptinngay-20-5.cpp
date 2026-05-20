	#include <stdio.h>
	#include <stdlib.h>
	
	//================= CAU TRUC =================
	typedef struct DaThuc {
	    int heso;
	    int somu;
	} DaThuc;
	
	typedef struct Node {
	    DaThuc data;
	    Node* next;
	} Node;
	
	typedef struct List {
	    Node* head;
	    Node* tail;
	} List;
	
	//================= KHAI BAO HAM =================
	void KhoiTao(List &l);
	Node* TaoNode(DaThuc x);
	void ThemCuoi(List &l, DaThuc x);
	void Nhap(List &l);
	void Xuat(List l);
	void RutGon(List &l);
	long Mu(int x, int n);
	long TinhGiaTri(List l, int x);
	void XoaNode(List &l, Node* prev, Node* cur);
	
	//================= MAIN =================
	int main() {
	    List l;
	    int x;
	
	    KhoiTao(l);
	
	    Nhap(l);
	
	    printf("\nDa thuc ban dau:\n");
	    Xuat(l);
	
	    printf("\nNhap x: ");
	    scanf("%d", &x);
	
	    printf("P(%d) = %ld\n", x, TinhGiaTri(l, x));
	
	    RutGon(l);
	
	    printf("\nSau khi rut gon:\n");
	    Xuat(l);
	
	    return 0;
	}
	
	//================= KHOI TAO =================
	void KhoiTao(List &l) {
	    l.head = l.tail = NULL;
	}
	
	//================= TAO NODE =================
	Node* TaoNode(DaThuc x) {
	    Node* p = (Node*)malloc(sizeof(Node));
	    if (!p) return NULL;
	
	    p->data = x;
	    p->next = NULL;
	    return p;
	}
	
	//================= THEM CUOI =================
	void ThemCuoi(List &l, DaThuc x) {
	    Node* p = TaoNode(x);
	    if (!p) return;
	
	    if (l.head == NULL) {
	        l.head = l.tail = p;
	    } else {
	        l.tail->next = p;
	        l.tail = p;
	    }
	}
	
	//================= NHAP =================
	void Nhap(List &l) {
	    int n;
	    scanf("%d", &n);
	
	    for (int i = 0; i < n; i++) {
	        DaThuc x;
	        scanf("%d%d", &x.heso, &x.somu);
	        ThemCuoi(l, x);
	    }
	}
	
	//================= XUAT DA THUC =================
	void Xuat(List l) {
	    Node* p = l.head;
	    int first = 1;
	
	    printf("P(x) = ");
	
	    while (p != NULL) {
	        if (p->data.heso != 0) {
	
	            if (!first && p->data.heso > 0)
	                printf(" + ");
	
	            if (p->data.somu == 0)
	                printf("%d", p->data.heso);
	            else if (p->data.somu == 1)
	                printf("%dx", p->data.heso);
	            else
	                printf("%dx^%d", p->data.heso, p->data.somu);
	
	            first = 0;
	        }
	
	        p = p->next;
	    }
	
	    if (first)
	        printf("0");
	
	    printf("\n");
	}
	
	//================= XOA NODE =================
	void XoaNode(List &l, Node* prev, Node* cur) {
	    if (prev == NULL) {
	        l.head = cur->next;
	    } else {
	        prev->next = cur->next;
	    }
	
	    if (cur == l.tail)
	        l.tail = prev;
	
	    free(cur);
	}
	
	//================= RUT GON DA THUC ================= // về sửa thêm 
	void RutGon(List &l) {
	    Node* p = l.head;
	
	    while (p != NULL) {
	        Node* prev = p;
	        Node* q = p->next;
	
	        while (q != NULL) {
	            if (q->data.somu == p->data.somu) {
	                p->data.heso += q->data.heso;
	
	                Node* temp = q;
	                q = q->next;
	                XoaNode(l, prev, temp);
	            } else {
	                prev = q;
	                q = q->next;
	            }
	        }
	
	        p = p->next;
	    }
	}
	
	//================= LUY THUA =================
	long Mu(int x, int n) {
	    long kq = 1;
	    for (int i = 0; i < n; i++)
	        kq *= x;
	    return kq;
	}
	
	//================= TINH GIA TRI =================
	long TinhGiaTri(List l, int x) {
	    long kq = 0;
	    Node* p = l.head;
	
	    while (p != NULL) {
	        kq += p->data.heso * Mu(x, p->data.somu);
	        p = p->next;
	    }
	
	    return kq;
	}
