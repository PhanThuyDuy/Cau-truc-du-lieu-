#include<stdio.h>
#include<stdlib.h>

typedef struct TNODE
{
	int key;
	struct TNODE* pLeft;
	struct TNODE* pRight;
} TNODE;

typedef struct TNODE* TREE;
TREE root;

// khai bao ham
void CreateTree(TREE &root);
void NLR(TREE root);
void LNR(TREE root);
void LRN(TREE root);
TNODE * searchNode(TREE root, int x);
TNODE* searchNode2(TREE root, int X);
void InsertTree(TREE  &root , int  x);
int delNode(TREE &root, int X);
void searchStandFor(TREE &p, TREE &q);

// ham moi
int DemNutLa(TREE root);
int DemNut1Con(TREE root);
int DemNut2Con(TREE root);
int DemNhoHonX(TREE root, int x);
int DemLonHonX(TREE root, int x);
int DemTrongKhoangXY(TREE root, int x, int y);
int ChieuCaoCay(TREE root);
void InDuongDiTimKiem(TREE root, int k);

int main()
{
	int x,y,k;
	TREE root = NULL;

	CreateTree(root);

	printf("\n\nNLR: ");
	NLR(root);
	printf("\nLNR: ");
	LNR(root);
	printf("\nLRN: ");
	LRN(root);

	printf("\n\nNhap gia tri  x = ");
	scanf("%d",&x);
	printf("Nhap gia tri  y = ");
	scanf("%d",&y);

	printf("\nSo nut la = %d", DemNutLa(root));
	printf("\nSo nut co dung 1 con = %d", DemNut1Con(root));
	printf("\nSo nut co dung 2 con = %d", DemNut2Con(root));
	printf("\nSo nut co khoa nho hon %d = %d",x,DemNhoHonX(root,x));
	printf("\nSo nut co khoa lon hon %d = %d",x,DemLonHonX(root,x));
	printf("\nSo nut co khoa > %d va < %d = %d",x,y,DemTrongKhoangXY(root,x,y));
	printf("\nChieu cao cua cay = %d", ChieuCaoCay(root));

	printf("\n\nNhap khoa k can tim = ");
	scanf("%d", &k);
	InDuongDiTimKiem(root, k);

	return 0;
}

void CreateTree(TREE &root)
{
	int x,n;
	scanf("%d",&n);
	for(int i=1; i<=n;i++)
	{
		scanf("%d",&x);
		InsertTree(root,x);
	}
}

void NLR(TREE root)
{
	if(root!=NULL)
	{
		printf("%d ",root->key);
		NLR(root->pLeft);
		NLR(root->pRight);
	}
}

void LNR(TREE root)
{
	if(root!=NULL)
	{
		LNR(root->pLeft);
		printf("%d ",root->key);
		LNR(root->pRight);
	}
}

void LRN(TREE root)
{
	if(root!=NULL)
	{
		LRN(root->pLeft);
		LRN(root->pRight);
		printf("%d ",root->key);
	}
}

TNODE * searchNode(TREE root, int x)
{
	TNODE *p = root;
	while(p != NULL)
	{
		if(x == p->key)
			return p;
		else if(x < p->key)
			p = p->pLeft;
		else
			p = p->pRight;
	}
	return NULL;
}

TNODE* searchNode2(TREE root, int x)
{
	if(root!=NULL)
	{
		if(root->key == x)
			return root;
		if(root->key > x)
			 return searchNode2(root->pLeft, x);
		else
			 return searchNode2(root->pRight, x);
	}
	return NULL;
}

void InsertTree(TREE  &root , int  x)
{
	if(root != NULL)
	{
		if(root->key==x) return;
		if(root-> key >x)
			InsertTree(root->pLeft,x);
		else
			InsertTree(root->pRight,x);
	}
	else
	{
		root= new TNODE;
		root->key=x;
		root->pLeft=root->pRight=NULL;
	}
}

int DemNutLa(TREE root)
{
	if(root==NULL) return 0;
	if(root->pLeft==NULL && root->pRight==NULL) return 1;
	return DemNutLa(root->pLeft)+DemNutLa(root->pRight);
}

int DemNut1Con(TREE root)
{
	if(root==NULL) return 0;
	if((root->pLeft==NULL && root->pRight!=NULL)||(root->pLeft!=NULL && root->pRight==NULL))
		return 1+DemNut1Con(root->pLeft)+DemNut1Con(root->pRight);
	return DemNut1Con(root->pLeft)+DemNut1Con(root->pRight);
}

int DemNut2Con(TREE root)
{
	if(root==NULL) return 0;
	if(root->pLeft!=NULL && root->pRight!=NULL)
		return 1+DemNut2Con(root->pLeft)+DemNut2Con(root->pRight);
	return DemNut2Con(root->pLeft)+DemNut2Con(root->pRight);
}

int DemNhoHonX(TREE root, int x)
{
	if(root==NULL) return 0;
	if(root->key < x)
		return 1+DemNhoHonX(root->pLeft,x)+DemNhoHonX(root->pRight,x);
	return DemNhoHonX(root->pLeft,x)+DemNhoHonX(root->pRight,x);
}

int DemLonHonX(TREE root, int x)
{
	if(root==NULL) return 0;
	if(root->key > x)
		return 1+DemLonHonX(root->pLeft,x)+DemLonHonX(root->pRight,x);
	return DemLonHonX(root->pLeft,x)+DemLonHonX(root->pRight,x);
}

int DemTrongKhoangXY(TREE root, int x, int y)
{
	if(root==NULL) return 0;
	if(root->key > x && root->key < y)
		return 1+DemTrongKhoangXY(root->pLeft,x,y)+DemTrongKhoangXY(root->pRight,x,y);
	return DemTrongKhoangXY(root->pLeft,x,y)+DemTrongKhoangXY(root->pRight,x,y);
}

int ChieuCaoCay(TREE root)
{
	if(root==NULL) return -1;
	int left=ChieuCaoCay(root->pLeft);
	int right=ChieuCaoCay(root->pRight);
	return (left>right?left:right)+1;
}

void InDuongDiTimKiem(TREE root, int k)
{
	printf("\nCac khoa duyet qua khi tim %d: ", k);
	while(root != NULL)
	{
		printf("%d ", root->key);
		if(root->key == k)
		{
			printf("-> Tim thay!");
			return;
		}
		else if(k < root->key)
			root = root->pLeft;
		else
			root = root->pRight;
	}
	printf("-> Khong tim thay!");
}
