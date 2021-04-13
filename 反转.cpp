反转           
void Reverse(LinkList &L)
{
    LinkList *p=L->next,*q;
    L->next=NULL;
    while (p!=NULL)     //扫描所有的结点
    {
        q=p->next;      //让q指向*p结点的下一个结点
        p->next=L->next;    //总是将*p结点作为第一个数据结点
        L->next=p;
        p=q;            //让p指向下一个结点
    }
}


