��ת           
void Reverse(LinkList &L)
{
    LinkList *p=L->next,*q;
    L->next=NULL;
    while (p!=NULL)     //ɨ�����еĽ��
    {
        q=p->next;      //��qָ��*p������һ�����
        p->next=L->next;    //���ǽ�*p�����Ϊ��һ�����ݽ��
        L->next=p;
        p=q;            //��pָ����һ�����
    }
}


