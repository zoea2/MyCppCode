#include <iostream>
using namespace std;
template <typename T>
void inorder_recursive(BinaryNode<T>* root, void (*visit)(T &x))
{
    if (root != NULL)
    {
        inorder_recursive(root->left,visit);
        visit(root->elem);
        inorder_recursive(root->right,visit);
    }
}
template <typename T>
void inorder(BinaryNode<T>* root, void (*visit)(T &x))
{
    BinaryNode<T>* stack[1000], *p;
    int tag[1000],top=0;
    p = root;
    while(p || top != 0)
    {
        while(p)
        {
            top++;
            stack[top]=p;
            tag[top]=0;
            p=p->left;
            //从根开始，左结点依次入栈
        }
        if(top> 0)
        {
            if(tag[top]==1)
            {
                //表示是从该结点的右子树返回
                p=stack[top];
                top--;
                p=NULL;//将p指向NULL,则下次进入while循环时，不做左子树入栈操作
            }
            else
            {   //表明是从该结点左子树返回，应访问该节点后继续访问其右子树
                p=stack[top];
                visit(p->elem);
                if(top> 0)
                {
                    p=p->right;
                    tag[top]=1;  //表明该结点的右子树已访问
                }
            } //end of else
        } //end of if
    }//end of while
}
