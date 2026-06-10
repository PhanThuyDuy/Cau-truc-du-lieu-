#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

	typedef struct Tinh 
	{
		char maso[20];
		float canha;
		float canhb;
		float canhc;
	
	}Tinh;
	
	typedef struct Note
	{
		Tinh Info;
		Note* pNext;
		Note* pPrev;
	}Note;
	
	typedef struct List
	{
		Note* pHead;
		Note* pTail; 
	}List;
	
	// Khai bao ham 
		void Init(List &L);
		Note* CreateNote(Tinh x);
		void AddTail(List &L,Note*p);
		void nhapthongtin(Tinh &x);
		void NhapDS(List &L, int n);
		float ChuVi(Tinh x);
		int laTamGiacVuong(Tinh x);
		int laTamGiacVuongCan(Tinh x);
		int DemTamGiacVuong(List L);
		void XoaA1(List &L);
		void TangCanh(List &L);
		void InDS(List L);
		// Ham chinh 
		int main()
	{
			List L;
			Init(L);
		
			int n;
			printf("Nhap so tam giac: ");
			scanf("%d", &n);
		
			NhapDS(L, n);
		
			printf("\n--- DANH SACH ---\n");
			InDS(L);
		
			printf("\nSo tam giac vuong: %d\n", DemTamGiacVuong(L));
		
			printf("\n--- TAM GIAC VUONG CAN ---\n");
			InMaVuongCan(L);
		
			XoaA1(L);
			TangCanh(L);
		
			return 0;
	}
			
		// khoi tao ds rong 
		void Init(List &L)
		{
			L.pHead = NULL;
			L.pTail = NULL;
		}
		
		Note* CreateNote(Tinh x)
		{
			Note*p = new Note ;
			
			if(p==NULL)
			{
				printf("Khong du bo nho!\n");
				exit(1);
			}
			p-> Info = x;
			p-> pPrev= NULL;
			p-> pNext= NULL; 
		return p; 
		}
		
		void AddTail(List &L,Note* p)
		{
			if(L.pHead == NULL)
			{	
				L.pHead = p;
				L.pTail = p;
			}
			else 
			{
			    L.pTail -> pNext = p; 
				p-> pPrev = L.pTail;
				L.pTail = p;
			}
		}
		
		
		
		
		void nhapthongtin(Tinh &x)
		{
			printf("Nhap ma so");
			scanf("%s",x.maso);
			
			
			do {
			    printf("Nhap 3 canh a, b, c: ");
			    scanf("%f%f%f", &x.canha, &x.canhb, &x.canhc);
			    
				if( x.canha <= 0|| x.canhb <= 0 || x.canhc <= 0 ||
			           x.canha + x.canhb <= x.canhc ||
			           x.canha + x.canhc <= x.canhb ||
			           x.canhb + x.canhc <= x.canha )
			    {
			   		printf("Nhap sai, vui long nhap lai!\n");
			    }
			
			} while (  x.canha <= 0|| x.canhb <= 0 || x.canhc <= 0 ||
			           x.canha + x.canhb <= x.canhc ||
			           x.canha + x.canhc <= x.canhb ||
			           x.canhb + x.canhc <= x.canha );
		}
		
		
	
			void NhapDS(List &L, int n)
		{
		    Tinh x;
		
		    for(int i = 1; i <= n; i++)
		    {
		        printf("\nNhap tam giac thu %d:\n", i);
		
		        nhapthongtin(x);
		
		        Note *p = CreateNote(x);
		
		        AddTail(L, p);
		    }
		}
			
					
				float ChuVi(Tinh x)
		{
			return x.canha + x.canhb + x.canhc;
		}
		
		float DienTich(Tinh x)
		{
			float p = ChuVi(x) / 2;
			return sqrt(p * (p - x.canha) * (p - x.canhb) * (p - x.canhc));
		}
		
		
		int laTamGiacVuong(Tinh x)
		{
			float a = x.canha, b = x.canhb, c = x.canhc;
		
			
			float max = a, x1 = b, x2 = c;
		
			if(max < x1){ float t = max; max = x1; x1 = t; }
			if(max < x2){ float t = max; max = x2; x2 = t; }
		
			return (fabs(max*max - (x1*x1 + x2*x2)) < 0.0001);
		}
		
	
		int laTamGiacVuongCan(Tinh x)
		{
			if(laTamGiacVuong(x))
			{
				if(x.canha == x.canhb || x.canha == x.canhc || x.canhb == x.canhc)
					return 1;
			}
			return 0;
		}
		
				
				// in ds 
				void InDS(List L)
		{
			Note *p = L.pHead;
		
			while(p != NULL)
			{
				Tinh x = p->Info;
		
				printf("\nMa so: %s", x.maso);
				printf("\nCanh a=%.2f b=%.2f c=%.2f", x.canha, x.canhb, x.canhc);
				printf("\nChu vi = %.2f", ChuVi(x));
				printf("\nDien tich = %.2f\n", DienTich(x));
		
				p = p->pNext;
			}
		}
		
				
				int DemTamGiacVuong(List L)
		{
			int dem = 0;
			Note *p = L.pHead;
		
			while(p != NULL)
			{
				if(laTamGiacVuong(p->Info))
					dem++;
		
				p = p->pNext;
			}
		
			return dem;
		}
		
				void InMaVuongCan(List L)
		{
			Note *p = L.pHead;
		
			while(p != NULL)
			{
				if(laTamGiacVuongCan(p->Info))
				{
					printf("\nMa tam giac vuong can: %s", p->Info.maso);
				}
		
				p = p->pNext;
			}
		}
				
			
			void XoaA1(List &L)
		{
			Note *p = L.pHead;
		
			while(p != NULL)
			{
				Note *q = p;
				p = p->pNext;
		
				if(q->Info.canha == 1)
				{
					// n?u là head
					if(q == L.pHead)
						L.pHead = q->pNext;
		
					// n?u không ph?i tail
					if(q->pNext != NULL)
						q->pNext->pPrev = q->pPrev;
					else
						L.pTail = q->pPrev;
		
					// n?u không ph?i head
					if(q->pPrev != NULL)
						q->pPrev->pNext = q->pNext;
		
					delete q;
				}
			}
		}
		
				
				void TangCanh(List &L)
		{
			Note *p = L.pHead;
		
			while(p != NULL)
			{
				p->Info.canha += 1;
				p->Info.canhb += 1;
				p->Info.canhc += 1;
		
				p = p->pNext;
			}
		}
