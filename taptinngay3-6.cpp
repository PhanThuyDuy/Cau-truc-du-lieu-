#include<stdio.h>
#include<stdlib.h>

#define ORDER 5
#define Ndiv2 2
#define TRUE 1
#define FALSE -1

typedef struct tagNODE{
    int NumTree;
    int Key[ORDER-1];
    struct tagNODE *Branch[ORDER];
} *NODEPTR;

NODEPTR Root;

// khai bao ham 
void Init();
int NodeSearch(NODEPTR p,int k);
NODEPTR Search(int k,int &Position,int &Found);

/* Them */
void InsertKey(int k);
void InsertLeaf(NODEPTR s,int k,int position);
void Split(NODEPTR nd,int newkey,NODEPTR newnode,int pos,
           NODEPTR &nd2,int &midkey);
void InsNode(NODEPTR p,int newkey,NODEPTR newnode,int pos);
void Copy(NODEPTR nd,int first,int last,NODEPTR nd2);

/* Nut */
NODEPTR Father(NODEPTR nd);
NODEPTR MakeRoot(int k);
NODEPTR GetNode();

/* Duyet - xuat */
void Scan(NODEPTR p);
void OutputTree(NODEPTR p,int level);

/* Xoa */
void DelKey(int k);
void DelLeaf(NODEPTR p,int pos);
void DelNode(NODEPTR p,int pos);
void BorrowBrother(NODEPTR p,int pos);
void Combine(NODEPTR &p,int pos);

int main()
{
    Init();

    int n,x;
    int pos,found;
    NODEPTR p;

    /* Tao cay */
    printf("Nhap so luong khoa: ");
    scanf("%d",&n);

    printf("Nhap cac khoa:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        InsertKey(x);
    }

    /* In cay */
    printf("\nCay B-Tree:\n");
    OutputTree(Root,0);

    /* Duyet Scan */
    printf("\nScan: ");
    Scan(Root);
    printf("\n");

    /* Tim kiem */
    printf("\nNhap khoa can tim: ");
    scanf("%d",&x);

    p=Search(x,pos,found);

    if(found==TRUE)
        printf("Tim thay khoa %d\n",x);
    else
        printf("Khong tim thay khoa %d\n",x);

    /* Xoa */
    printf("\nNhap khoa can xoa: ");
    scanf("%d",&x);

    DelKey(x);

    printf("\nCay sau khi xoa:\n");
    OutputTree(Root,0);

    printf("\nScan sau khi xoa: ");
    Scan(Root);

    return 0;
}

void Init(){
    Root=NULL;
}

int NodeSearch(NODEPTR p,int k){

    int i;

    for(i=0;i<p->NumTree-1 && p->Key[i]<k;i++);

    return i;
}

NODEPTR Search(int k,int &Position,int &Found){

    int i=0;
    NODEPTR p=Root,q=NULL;

    while(p!=NULL){

        i=NodeSearch(p,k);

        if(i<p->NumTree-1 && k==p->Key[i]){
            Found=TRUE;
            Position=i;
            return p;
        }

        q=p;
        p=p->Branch[i];
    }

    Found=FALSE;
    Position=i;

    return q;
}

void InsertKey(int k){

    int pos,found;
    NODEPTR s;

    if(Root==NULL)
        Root=MakeRoot(k);

    else{

        s=Search(k,pos,found);

        if(found==TRUE)
            printf("\nBi trung khoa!\n");

        else
            InsertLeaf(s,k,pos);
    }
}

void InsertLeaf(NODEPTR s,int k,int position){

    NODEPTR nd=s,nd2,f=Father(nd),newnode=NULL;
    int pos=position,newkey=k,midkey;

    while(f!=NULL && nd->NumTree==ORDER){

        Split(nd,newkey,newnode,pos,nd2,midkey);

        nd=f;
        newkey=midkey;
        newnode=nd2;
        pos=NodeSearch(f,midkey);
        f=Father(nd);
    }

    if(nd->NumTree<ORDER){

        InsNode(nd,newkey,newnode,pos);
        return;
    }

    Split(nd,newkey,newnode,pos,nd2,midkey);

    Root=MakeRoot(midkey);
    Root->Branch[0]=nd;
    Root->Branch[1]=nd2;
}

void Split(NODEPTR nd,int newkey,NODEPTR newnode,int pos,NODEPTR &nd2,int &midkey){

    NODEPTR p=GetNode();

    if(pos>Ndiv2){

        Copy(nd,Ndiv2+1,ORDER-2,p);

        InsNode(p,newkey,newnode,pos-Ndiv2-1);

        nd->NumTree=Ndiv2+1;
        midkey=nd->Key[Ndiv2];
        nd2=p;
        return;
    }

    else if(pos==Ndiv2){

        Copy(nd,Ndiv2,ORDER-2,p);

        nd->NumTree=Ndiv2+1;
        p->Branch[0]=newnode;

        midkey=newkey;
        nd2=p;
        return;
    }

    else{

        Copy(nd,Ndiv2,ORDER-2,p);

        nd->NumTree=Ndiv2;
        midkey=nd->Key[Ndiv2-1];

        InsNode(nd,newkey,newnode,pos);

        nd2=p;
    }
}

void InsNode(NODEPTR p,int newkey,NODEPTR newnode,int pos){

    for(int i=p->NumTree-1;i>=pos+1;i--){

        p->Branch[i+1]=p->Branch[i];
        p->Key[i]=p->Key[i-1];
    }

    p->Key[pos]=newkey;
    p->Branch[pos+1]=newnode;
    p->NumTree++;
}

void Copy(NODEPTR nd,int first,int last,NODEPTR nd2){

    for(int i=first;i<=last;i++)
        nd2->Key[i-first]=nd->Key[i];

    for(int i=first;i<=last+1;i++)
        nd2->Branch[i-first]=nd->Branch[i];

    nd2->NumTree=last-first+2;
}

NODEPTR Father(NODEPTR nd){

    NODEPTR p=Root;
    int i;

    if(p==nd)
        return NULL;

    while(p!=NULL){

        i=NodeSearch(p,nd->Key[0]);

        if(p->Branch[i]==nd)
            return p;

        p=p->Branch[i];
    }

    return NULL;
}

NODEPTR MakeRoot(int k){

    NODEPTR p=new tagNODE;

    p->Key[0]=k;

    for(int i=0;i<ORDER;i++)
        p->Branch[i]=NULL;

    p->NumTree=2;

    return p;
}

NODEPTR GetNode(){

    NODEPTR p=new tagNODE;

    p->NumTree=0;

    for(int i=0;i<ORDER;i++)
        p->Branch[i]=NULL;

    return p;
} 

void Scan(NODEPTR p){

    if(p==NULL)
        return;

    for(int i=0;i<p->NumTree-1;i++){

        Scan(p->Branch[i]);
        printf("%d ",p->Key[i]);
    }

    Scan(p->Branch[p->NumTree-1]);
}

void OutputTree(NODEPTR p,int level){

    if(p==NULL)
        return;

    for(int i=0;i<level;i++)
        printf("\t");

    for(int i=0;i<p->NumTree-1;i++)
        printf(".%d",p->Key[i]);

    printf(".\n");

    for(int i=0;i<p->NumTree;i++)
        OutputTree(p->Branch[i],level+1);
}

/* ==================== XOA ==================== */

void DelKey(int k);
void DelLeaf(NODEPTR p,int pos);
void DelNode(NODEPTR p,int pos);
void BorrowBrother(NODEPTR p,int pos);
void Combine(NODEPTR &p,int pos);

void DelKey(int k){

    int pos,found;

    NODEPTR p=Search(k,pos,found);

    if(found==FALSE){

        printf("\nKhong tim thay khoa %d de xoa\n",k);
        return;
    }

    /* k nam trong nut la */
    if(p->Branch[0]==NULL){

        DelLeaf(p,pos);
    }

    /* k nam trong nut khac la */
    else{

        NODEPTR q=p->Branch[pos];

        while(q->Branch[q->NumTree-1]!=NULL)
            q=q->Branch[q->NumTree-1];

        p->Key[pos]=q->Key[q->NumTree-2];

        DelLeaf(q,q->NumTree-2);
    }
}

void DelLeaf(NODEPTR p,int pos){

    NODEPTR q=Father(p);
    int i;

    DelNode(p,pos);

    while((p->NumTree < Ndiv2+1) && (p!=Root)){

        i=NodeSearch(q,p->Key[0]);

        /* tan cung trai */
        if((i==0)&&(q->Branch[i+1]->NumTree>Ndiv2+1)){

            BorrowBrother(q,i);
            return;
        }

        /* tan cung phai */
        if((i==q->NumTree-1)&&(q->Branch[i-1]->NumTree>Ndiv2+1)){

            BorrowBrother(q,i-1);
            return;
        }

        /* nam giua */
        if((i>0)&&(i<q->NumTree-1)){

            if(q->Branch[i+1]->NumTree>Ndiv2+1){

                BorrowBrother(q,i);
                return;
            }

            if(q->Branch[i-1]->NumTree>Ndiv2+1){

                BorrowBrother(q,i-1);
                return;
            }
        }

        /* hop nhat */
        if(i==q->NumTree-1)
            Combine(q,i-1);
        else
            Combine(q,i);

        p=q;
        q=Father(p);
    }
}

void DelNode(NODEPTR p,int pos){

    for(int i=pos;i<p->NumTree-2;i++){

        p->Key[i]=p->Key[i+1];
        p->Branch[i+1]=p->Branch[i+2];
    }

    p->NumTree--;
}

void BorrowBrother(NODEPTR p,int pos){

    NODEPTR left=p->Branch[pos];
    NODEPTR right=p->Branch[pos+1];

    /* muon ben trai (xoay phai) */
    if(left->NumTree>Ndiv2+1){

        for(int i=right->NumTree-1;i>=1;i--){

            right->Branch[i+1]=right->Branch[i];
            right->Key[i]=right->Key[i-1];
        }

        right->Branch[1]=right->Branch[0];

        right->Key[0]=p->Key[pos];
        right->Branch[0]=left->Branch[left->NumTree-1];
        right->NumTree++;

        p->Key[pos]=left->Key[left->NumTree-2];
        left->NumTree--;

        return;
    }

    /* muon ben phai (xoay trai) */
    if(right->NumTree>Ndiv2+1){

        left->Key[left->NumTree-1]=p->Key[pos];
        left->Branch[left->NumTree]=right->Branch[0];
        left->NumTree++;

        p->Key[pos]=right->Key[0];

        DelNode(right,0);
    }
}

void Combine(NODEPTR &p,int pos){

    NODEPTR left=p->Branch[pos];
    NODEPTR right=p->Branch[pos+1];

    left->Key[left->NumTree-1]=p->Key[pos];
    left->NumTree++;

    for(int i=0;i<right->NumTree-1;i++){

        left->Key[left->NumTree-1+i]=right->Key[i];
        left->Branch[left->NumTree-1+i]=right->Branch[i];
    }

    left->Branch[left->NumTree-1+(right->NumTree-1)]
        = right->Branch[right->NumTree-1];

    left->NumTree=left->NumTree+right->NumTree-1;

    DelNode(p,pos);

    p->Branch[pos]=left;

    delete right;

    if((p==Root)&&(p->NumTree<2)){

        Root=left;
        delete p;
        p=Root;
    }
}