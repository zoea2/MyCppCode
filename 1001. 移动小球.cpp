#include <iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;
struct list
{
    int data;
    list * next;
    list * pre;
};
void left(int i ,int j,list * head)
{

    list* p = head;
    list* q = head;

    while(p!= NULL)
    {
        if (p->data != i)
        p = p->next;
        else
        break;
    }

    while(q!= NULL)
    {
        if (q->data != j)
        q = q->next;
        else
        break;
    }
    if (p->next != q)
    {
        (p->pre)->next = p->next;
        if(p->next != NULL)
        (p->next)->pre = p->pre;
        (q->pre)->next = p;

        p->pre = q->pre;
        q->pre = p;
        p ->next = q;
    }




}
void right(int i ,int j,list * head)
{

    list* p = head;
    list* q = head;

    while(p!= NULL)
    {
        if (p->data != i)
        p = p->next;
        else
        break;
    }

    while(q!= NULL)
    {
        if (q->data != j)
        q = q->next;
        else
        break;
    }
    if (q->next != p)

    {
        (p->pre)->next = p->next;
        if(p->next != NULL)
        (p->next)->pre = p->pre;
        if(q->next != NULL)
        (q->next)->pre = p;
        p->next = q->next;
        q->next = p;
        p ->pre = q;
    }



}
int main()
{
    int t,num,n,con,x,y;
    cin>>t;
    while(t)
    {
        t--;
        list *head = new list;
        head->next = NULL;
        head->pre = NULL;
        head->data = 0;
        scanf ("%d", &num);
        list * temp;
        for (int i = num;i >0;i--)
        {
            temp = new list;
            temp->data = i;
            temp->next = head->next;
            if (temp->next != NULL)
            (temp->next)->pre = temp;
            head->next = temp;
            temp->pre = head;
        }
        cin>>n;
        while(n)
        {
            n--;
            scanf ("%d%d%d", &con, &x, &y);
            if (con == 1)
            left(x,y,head);
            else
            right(x,y,head);

        }
        for (int i = 0;i < num;i++)
        {
            head = head->next;
            cout<<head->data<<" ";
        }
        cout<<endl;

    }


}
