#include <iostream>
using namespace std;
struct Node
{
    int candy;
    Node * right;
    Node * left;
};
int main()
{
    int n,c;
    cin>>n;
    while(n)
    {
        int can[n];
        Node* head = new Node;
        head->right = NULL;
        head->left = NULL;
        Node * last = head;
        for (int i = 0;i < n;i++)
        {
            cin>>c;
            last->candy = c;
            if (i < n-1)
            {
                Node* temp = new Node;
                temp->right = head;
                temp->left = last;
                last->right = temp;
                last = temp;
                head->left = last;
            }
        }
        Node * temp0 = head;
        int count = 0;
        while (temp0->candy == (temp0->right)->candy)
        {
            temp0 = temp0->right;
            count++;
            if (count == n - 1)
            {
                cout<<"0"<<" "<<temp0->candy<<endl;
                break;
            }
        }
        if (count == n-1)
        {
            cin>>n;
            continue;
        }
        int count0 = 0;
        while(true)
        {
            count0++;
            temp0 = head;
            for (int i = 0;i < n;i++)
            {
                temp0->candy /= 2;
                can[i] = temp0->candy;
                temp0 = temp0->right;
            }
            temp0 = head->right;
            head->candy += can[n-1];
            for (int i = 0;i < n-1;i++)
            {
                temp0->candy += can[i];
                temp0 = temp0->right;
            }
            temp0 = head;
            count = 0;
            for (int i = 0;i < n;i++)
            {
                if (temp0->candy % 2 == 1)
                temp0->candy++;
                temp0 = temp0->right;
            }
            temp0 = head;
            while (temp0->candy == (temp0->right)->candy)
            {
                temp0 = temp0->right;
                count++;
                if (count == n - 1)
                {
                    cout<<count0<<" "<<temp0->candy<<endl;
                    break;
                }
            }
            if (count == n-1)
            break;
        }
        cin>>n;
    }
}
