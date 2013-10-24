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
            //�Ӹ���ʼ������������ջ
        }
        if(top> 0)
        {
            if(tag[top]==1)
            {
                //��ʾ�ǴӸý�������������
                p=stack[top];
                top--;
                p=NULL;//��pָ��NULL,���´ν���whileѭ��ʱ��������������ջ����
            }
            else
            {   //�����ǴӸý�����������أ�Ӧ���ʸýڵ�����������������
                p=stack[top];
                visit(p->elem);
                if(top> 0)
                {
                    p=p->right;
                    tag[top]=1;  //�����ý����������ѷ���
                }
            } //end of else
        } //end of if
    }//end of while
}
