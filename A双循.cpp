#include<stdio.h>
#include<stdlib.h>
typedef struct Dnode{
	int data;
	struct Dnode *pre,*next;
}Dnode,*Linklist;

//头
Linklist head(Linklist &L){
	Dnode *s;
	int x;
	L=(Linklist)malloc(sizeof(Dnode));
	L->next=L;
	L->pre=L;
	scanf("%d",&x);
	while(x!=999){
		s=(Dnode*)malloc(sizeof(Dnode));
		s->data=x;
		if(L->next==NULL){
			s->next=L;
			L->pre=s;
			s->pre=L;//
			L->next=s;//
		}else{
			s->next=L->next;
			L->next->pre=s;
			s->pre=L;//
			L->next=s;//	
		}
		scanf("%d",&x);
	}
	return L;
} 

//尾
Linklist tail(Linklist &L){
	int x;
	L=(Linklist)malloc(sizeof(Dnode));
	Dnode *s,*r=L;
	L->next=L;
	L->pre=L;
	scanf("%d",&x);
	while(x!=999){
		s=(Dnode*)malloc(sizeof(Dnode));
		s->data=x;
		s->pre=r;
		r->next=s;
		r=s;
		scanf("%d",&x);
	}//空表 
	if(L->next!=L){
		s->next=L;
		L->pre=s;
	}
	return L;
} 

//增 范围内！ 
bool insert(Linklist &L,int i ,int e){
	if(i<1)
		return false;
	Dnode *p;
	p=L;
	int j;
	while(j<i-1){
		p=p->next;	
		j++;
	}
	Dnode *s=(Dnode*)malloc(sizeof(Dnode));
	s->data=e;
	s->next=p->next;
	p->next->pre=s;
	s->pre=p;
	p->next=s;
	return true;
} 

//删
bool del(Linklist &L,int i){
	Dnode* p=L;
	if(i<1)
		return false;
	int j=0;
	while(p->next!=L&&j<i-1){
		p=p->next;
		j++;
	}
	if(p->next==L)
		return false;
	Dnode* s=p->next;
	p->next=s->next;
	s->next->pre=p;
	free(s);
	return true;
}  

//打印 
bool Print(Linklist &L) {
	if(L->next==L){
		printf("无"); 
	return false;	
	}
	Dnode* p;
	p=L->next;
	while(p!=L) {
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
	return true;
}

int main()
{
	Linklist L;
	tail(L);
	Print(L);
	del(L,1);
	Print(L);
}
