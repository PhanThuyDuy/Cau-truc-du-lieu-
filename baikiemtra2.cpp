#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// danh sach lien ket don 
 typedef struct Khachhang 
 {     char maso[20] ;
	   char hoten [50];
	   char sdt[15];
	   char maphong[10];
	   int songaythue;  
 }Khachhang;
 
 typedef struct Note 
 { 	Khachhang Info;
   	Note* pNext; 
 }Note;
 
 typedef struct List 
 { Note* pHead;
   Note* pTail;
 }List; 
 
// Khai bao ham 
	 
	void Init(List &L);
    Note* CreateNote(Khachhang x);
	void NhapKhachhang(Khachhang &x);
	void AddTail(List &L,Note* p);
	void NhapDS(List &L,int n);
    void XuatKhachhang(Khachhang x);
    void XuatDS(List L);
    int DemphongZ001(List L);
    long Dongia(char maphong[]);
    void Inthanhtien(List L);
 // Ham main 
 int main()
 { List L;
   int n ;
   
   Init(L);
  
   printf("\nNhap so luong khach hang: ");
   scanf("%d", &n);
   NhapDS(L,n);
   XuatDS(L);
  
   printf("\nSo khach thue phong Z001: %d",DemphongZ001(L));  
   printf("\nDanh sach thanh tien\n ");
 
   Inthanhtien(L);
 
 return 0;
 
 }
 
 
 	void Init(List &L)
 {  
 	L.pHead = NULL; 
    L.pTail = NULL;
 }
 
 
 Note* CreateNote(Khachhang x)
 { 	 Note* p = new Note;
 
	 if(p == NULL)
	 return NULL;
	 
	 p-> Info = x ;
	 p-> pNext = NULL;
 		
	return p;
 }
 
 	// nhap thong tin khach hang 
 	void NhapKhachhang(Khachhang &x)
 { 
  
   fflush(stdin);
   printf("\nNhap ma so : ");
   gets(x.maso);
   
   fflush(stdin);
   printf("\nNhap ho va ten: ");
   gets(x.hoten);
   
   fflush(stdin);
   printf("\nNhap so dien thoai: ");
   gets(x.sdt);
  
   fflush(stdin);
   printf("\nNhap ma phong: ");
   gets(x.maphong);
   
   printf("\nNhap so ngay thue: ");
   scanf("%d",&x.songaythue);
   
 }
 
 	void AddTail(List &L,Note* p)
 { 
 	if (L.pHead==NULL)
    L.pHead = L.pTail = p;
   
    else
	L.pTail -> pNext = p ;
	L.pTail = p ;
 
 }
 
 	void NhapDS(List &L,int n)
 {
	Khachhang x ; 
	
	for(int i = 1 ; i <= n; i++)
	{ 
		printf("\nNhap khach hang %d",i);  
	    NhapKhachhang(x);
	    Note * p =CreateNote(x);
	    AddTail(L,p);
	 } 
 }
 
 
 	void XuatKhachhang(Khachhang x,int stt)
 { 
   	
   printf("\nkhach hang %d",stt); 
   
   printf("\nMa so :%s ",x.maso);
  
   printf("\nHo va ten:%s ",x.hoten);
   
   printf("\nSo dien thoai:%s ",x.sdt);
   
   printf("\nMa phong: %s ",x.maphong);
   
   printf("\nSo ngay thue :%d \n",x.songaythue);
 
 }
 
 	void XuatDS(List L)
 {
 	Note* p = L.pHead;
    int stt = 1 ;
 	
	 while ( p !=NULL) 
	 {
	 XuatKhachhang(p->Info, stt);
	 stt++;
	 p = p -> pNext; 
  	 }
 }
 
	 int DemphongZ001(List L)
 {
		int dem = 0;
		Note* p = L.pHead; 
	
		while(p!=NULL)
		{
			if(strcmp(p->Info.maphong, "Z001") == 0 ) 
	 		dem++; 
	 		p = p->pNext ;
	 	}
		return dem ;
 
 }
 
	long Dongia(char maphong[])
{ 
	if(maphong[0]=='A')
 		return 240000;
	if(maphong[0]=='B')
		return 200000;
	else 
		return 120000;

}

 	void Inthanhtien(List L)
{    
		Note*p = L.pHead;
		
	while (p!=NULL)	
	{
		long thanhtien = p-> Info.songaythue * Dongia(p->Info.maphong);
		 printf("\nMa so %-15s  Ho va ten %-20s  Thanh tien %-15ld \n",
		 p->Info.maso,p->Info.hoten,thanhtien);
		
		 p = p-> pNext ;
	}

}
