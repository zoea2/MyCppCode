#include <iostream>
using namespace std;
struct node
{
    int data;
    int bf;
    node * lchild, *rchild;
};
void r_rotate(node **t)
{
    node *lc = (*t)->lchild;
    (*t)->lchild = lc->rchild;
    lc->rchild = *t;
    *t = lc;
}
void l_rotate(node **t)
{
    node *lc = (*t)->rchild;
    (*t)->rchild = lc->lchild;
    lc->lchild = *t;
    *t = lc;
}
void LeftBalance(node ** T)
{
    node *lc = (*T)->lchild;
    switch(lc->bf)
    {
        case 1:
            (*T)->bf = lc->bf = 0;
            r_rotate(T);
            break;
        case -1:
            node *rd = lc->rchild;
            switch(rd->bf)
            {
                case 1:(*T)->bf = -1;lc->bf = 0;break;
                case 0:(*T)->bf = 0;lc->bf = 0;break;
                case -1:(*T)->bf = 0;lc->bf = 1;break;

            }
            rd->bf = 0;
            l_rotate(&(*T)->lchild);
            r_rotate(T);
    }
}
void RightBalance(node ** T)
{
    node *lc = (*T)->rchild;
    switch(lc->bf)
    {
        case -1:
            (*T)->bf = lc->bf = 0;
            l_rotate(T);
            break;
        case 1:
            node *rd = lc->lchild;
            switch(rd->bf)
            {
                case -1:(*T)->bf = 1;lc->bf = 0;break;
                case 0:(*T)->bf = 0;lc->bf = 0;break;
                case 1:(*T)->bf = 0;lc->bf = -1;break;

            }
            rd->bf = 0;
            r_rotate(&((*T)->rchild));
            l_rotate(T);
    }
}
void insert(node** T,int e,bool &taller,node ** f)
{
    if (*T == NULL)
    {
        if (*f != *T)
        {
            (*T) = new node;
            (*T)->data = e;
            (*T)->lchild = NULL;
            (*T)->rchild = NULL;
            (*T)->bf = 0;
            taller = true;

            if (e > (*f)->data)
            (*f)->rchild = *T;
            else
            (*f)->lchild = *T;
        }
        else
        {
            node *temp = new node;
            temp->data = e;
            temp->lchild = NULL;
            temp->rchild = NULL;
            temp->bf = 0;
            *T = temp;
            taller = true;


        }
    }
    else
    {
        if (e < (*T)->data)
        {
            insert(&((*T)->lchild),e,taller,T);
            if (taller)
            {
                switch((*T)->bf)
                {
                    case 1:
                        LeftBalance(T);
                        taller = false;
                        break;
                    case 0:
                        (*T)->bf = 1;
                        taller = true;
                        break;
                    case -1:
                        (*T)->bf = 0;
                        taller = false;
                        break;
                }
            }
        }
        else if (e > (*T)->data)
        {

            insert(&((*T)->rchild),e,taller,T);
            if (taller)
            {
                switch((*T)->bf)
                {
                    case 1:
                        (*T)->bf = 0;
                        taller = false;
                        break;
                    case 0:
                        (*T)->bf = -1;
                        taller = true;
                        break;
                    case -1:
                        RightBalance(T);
                        taller = false;
                        break;
                }
            }
        }
    }

}
void pre(node *t)
{
    if (t != NULL)
    {
        cout<<t->data<<" ";
        pre(t->lchild);
        pre(t->rchild);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int num;
        cin>>num;
        bool taller;
        int temp;
        node *T = NULL;
        for (int i = 0;i < num;i++)
        {
            cin>>temp;
            insert(&T,temp,taller,&T);

        }
        pre(T);
        cout<<endl;

    }
}
