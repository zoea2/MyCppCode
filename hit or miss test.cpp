#include<iostream>
#include<queue>
using namespace std;
int main(){
    int testCase;
    int caseNo = 0;
    cin>>testCase;
    while(testCase--){
        caseNo ++; //��case�ı��
        int playerNum;
        cin>>playerNum;

        //��ʼ��ÿ��player��deck
        queue<short> deck[11];
        short  final[11];
        short data;
        for(int i = 0; i < 52; i++)
        {
            cin>>data;
            deck[0].push(data);
        }

        bool isComplish = false;
        short sizeScalar[11] = {0}; //  ��¼ÿһ���Ѿ��߹�����Ŀ
        int//��Ӧ��ÿһ������������
        short count[11] = {0};
        //�������״̬
        int j = 0;
        int totalSize = 52;
        while(!isComplish){
            if(deck[j].empty()){
                j++;
                if(j >= playerNum)
                    j = 0;
                continue;
            }
            sizeScalar[j]++;
            count[j]++;
            if(count[j] ==  deck[j].front()){

                deck[j+1].push(deck[j].front());    //������˾�ֱ��ɾ������
                sizeScalar[j] = 0;
                if(j+1 == playerNum){
                    totalSize -- ;              //���ˣ���������Ҫ����
                }

                final[j] = deck[j].front();
                deck[j].pop();
            }
            else
            {

                deck[j].push(deck[j].front());
                deck[j].pop();
            }

            if(count[j] == 13){
                count[j] = 0;
            }
            if(sizeScalar[j] > (int)deck[j].size()*13)
            {
                isComplish = false;
                break;
            }

            if(totalSize == 0){
                isComplish = true;
            }

            j++;
            if(j >= playerNum){
                j = 0;
            }
        }
        if(isComplish == true){
            cout<<"Case "<<caseNo<<":";
            int i = 0;
            while(i < playerNum){
                cout<<" "<<final[i];
                i++;
            }
            cout<<endl;
        }
        else
        {
            cout<<"Case "<<caseNo<<": unwinnable"<<endl;
        }

    }

    return 0;
}
