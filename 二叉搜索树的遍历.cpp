#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node * left;
    node * right;
    node()
    {
        left = NULL;
        right = NULL;
    }
};
void preorder(node * root)
{
    node * temp = root;
    if (temp != NULL)
    {
        cout<<temp->data<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }
}
void inorder(node * root)
{
    node * temp = root;
    if (temp != NULL)
    {

        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }
}
int main()
{
    int num;
    cin>>num;
    while (num)
    {
        node * root = new(node);
        int temp;
        cin>>temp;
        root->data = temp;
        for (int i = 1;i < num;i++)
        {
            node * temp0 = root;
            node * temp1 = root;
            cin>>temp;
            while (temp0!=NULL)
            {
                temp1 = temp0;
                if (temp0->data > temp)
                {
                    temp0 = temp0->left;
                }
                else if (temp > temp0->data)
                {
                    temp0 = temp0->right;
                }
            }
            if (temp > temp1->data)
            {
                node* temp2 = new(node);
                temp2->data = temp;
                temp1->right = temp2;
            }
            else
            {
                node* temp2 = new(node);
                temp2->data = temp;
                temp1->left = temp2;
            }

        }
        inorder(root);
        cout<<endl;
        preorder(root);
        cout<<endl;
        cin>>num;
    }
}
