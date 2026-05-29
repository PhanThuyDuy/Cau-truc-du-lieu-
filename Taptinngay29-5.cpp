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


// ham chinh
int main()
{
	int x;
	TREE root = NULL;

	CreateTree(root);

	printf("\n\nNLR: ");
	NLR(root);

	printf("\nLNR: ");
	LNR(root);

	printf("\nLRN: ");
	LRN(root);

	printf("\nNhap khoa x can tim = ");
	scanf("%d",&x);

	if(searchNode(root,x)!=NULL)
		printf("Tim thay %d",x);
	else
		printf("Khong tim thay %d",x);

	// tim kieu de quy 
	/*	if(searchNode2(root,x)!=NULL)
			printf("Tim thay %d",x);
		else
			printf("Khong tim thay %d",x); */ 


   // xoa nut co khoa x 
   
   if(delNode(root, x) == 1)
    {
        printf("\nXoa thanh cong %d!", x);
        printf("\nCay sau khi xoa : ");
       
	    printf("\n\nNLR: ");
		NLR(root);

		printf("\nLNR: ");
		LNR(root);
	
		printf("\nLRN: ");
		LRN(root);
    }
    else
    {
        printf("\nXoa that bai (khong tim thay node)!");
    }
	
	
	return 0;
}


// tao cay 

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




// Node-Left-Right
void NLR(TREE root)
{
	if(root!=NULL)
	{
		printf("%d ",root->key);
		NLR(root->pLeft);
		NLR(root->pRight);
	}
}


// Left-Node-Right
void LNR(TREE root)
{
	if(root!=NULL)
	{
		LNR(root->pLeft);
		printf("%d ",root->key);
		LNR(root->pRight);
	}
}


// Left-Right-Node
void LRN(TREE root)
{
	if(root!=NULL)
	{
		LRN(root->pLeft);
		LRN(root->pRight);
		printf("%d ",root->key);
	}
}


// tim mot phan tu x khong de quy
TNODE * searchNode(TREE root, int x)
{
	TNODE *p = root;

	while(p != NULL)
	{
		if(x == p->key)
			return p;
		else
			if(x < p->key)
				p = p->pLeft;
			else
				p = p->pRight;
	}

	return NULL;
}

// tim mot phan tu x  de quy
TNODE* searchNode2(TREE root, int x)
{
	if(root!=NULL)	
	{
		if(root->key == x)
			return root;
		if(root->key > x)
			 return searchNode(root->pLeft, x);
		else
			 return searchNode(root->pRight, x);
	}
	return NULL;
} 










// them mot nut vao cay

void  InsertTree(TREE  &root , int  x)
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





// tim node the mang
void searchStandFor(TREE &p, TREE &q)
{
	if(q->pRight != NULL)
		searchStandFor(p,q->pRight);
	else
	{
		p->key = q->key;
		p = q;

		if(q->pLeft != NULL)
			q = q->pLeft;
		else
			q = q->pRight;
	}
}


// huy 1 phan tu co khoa X
int delNode(TREE &root, int x) 
{
	if(root == NULL)
		return 0;

	if(root->key > x) 
		return delNode(root->pLeft, x);

	if(root->key < x) 
		return delNode(root->pRight, x);

	// root->key == x
	TNODE* p = root;

	if(root->pLeft == NULL)
		root = root->pRight;
	else
		if(root->pRight == NULL)
			root = root->pLeft;
		else
			searchStandFor(p, root->pLeft);

	free(p);
	return 1;
}
