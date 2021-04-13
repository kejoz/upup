#include<stdio.h>
#include<stdlib.h>
typedef struct Dnode{
	int data;
	struct Dnode *pre,*next;
}Dnode,*Linklist;

//头
Linklist head(Linklist &L)
{
	Dnode *s;
	L=(Linklist)malloc(sizeof(Dnode));
	L->pre=NULL;
	L->next=NULL;
	int x;
	scanf("%d",&x);
	while(x!=1){
		s=(Dnode*)malloc(sizeof(Dnode));
		s->data=x;
		s->next=L->next;
		if(L->next!=NULL)
			L->next->pre=s;
		s->pre=L;
		L->next=s;
		scanf("%d",&x);
	}
	return L;
}
 
//尾
Linklist tail(Linklist &L) 
{
	L=(Linklist)malloc(sizeof(Dnode));
	Dnode *s,*r=L;
	L->pre=NULL;
	int x;
	scanf("%d",&x);
	while(x!=1){
		s=(Dnode*)malloc(sizeof(Dnode));
		s->data=x;
		r->next=s;
		s->pre=r;
		r=s;
		scanf("%d",&x);
	}
	r->next=NULL;
	return L;
}

//增
bool insert(Linklist &L,int i,int e)
{
	if(i<1)
		return false;
	Dnode* p;
	p=L;
	int j=0;
	while(p!=NULL&&j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL)
		return false;
	Dnode* s=(Dnode*)malloc(sizeof(Dnode));
	s->data=e;
	s->next=p->next;
	p->next->pre=s;
	s->pre=p;
	p->next=s;	
	return true;
 } 
 //删
bool del(Linklist &L,int i)
{
	if(i<1)
		return false;
	Dnode* p;
	p=L;
	int j=0;
	while(p!=NULL&&j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL)
		return false;
	Dnode *q=p->next;
	p->next=q->next;
	q->next->pre=p;
	free(q);
	return true;
}
//改  
bool change(Linklist &L,int i,int e)
{
	if(i<1)
		return false;
	Dnode* p;
	p=L;
	int j=0;
	while(p!=NULL&&j<i){
		p=p->next;
		j++;
	}
	if(p==NULL)
		return false;
	p->data=e;
	return true;
}

//打印 
void Print(Linklist &L) {
	Dnode* p;
	p=L->next;
	while(p!=NULL) {
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	Linklist L;
	tail(L);
	Print(L);
	insert(L,2,777);
	Print(L);
	del(L,1);
	Print(L);
	change(L,5,555);
	Print(L);
}
