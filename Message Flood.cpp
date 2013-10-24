#include <iostream>
#include<cstring>
using namespace std;
int y = 0;
typedef char STRING_11[11];
void lowerCase(char *str){
    while(*str!='\0'){
        if(*str<'a'){
            *str+=0x20;
        }
        str++;
    }
}



int main()
{
	int n[100],m[100];

	for (int f = 0;f < 100 ;f++)
	{
		cin>>n[f];
		if (n[f] == 0)
			break;
		cin>>m[f];
		STRING_11 *friends=new STRING_11[n[f]];

		int row;
		for ( row = 0;row < n[f];row++)
		{
			cin>>friends[row];
			lowerCase(friends[row]);
		}
		STRING_11 *sentFriends=new STRING_11[n[f]];

		for ( row = 0;row < m[f];row++)
		{
			cin>>sentFriends[row];
			lowerCase(sentFriends[row]);
		}

		for (int i = m[f]-1;i >= 1;i--){
			char currentMax1[11];

			strcpy(currentMax1, sentFriends[0]);
			int currentMaxIndex1 = 0;
			for (int j = 1;j <= i;j++)
			{
				if (strcmp(currentMax1 , sentFriends[j]) < 0)
				{
					strcpy(currentMax1, sentFriends[j]);

					currentMaxIndex1 = j;
				}
			}
			if (currentMaxIndex1 != i)	{
				strcpy(sentFriends[currentMaxIndex1], sentFriends[i]);
				strcpy(sentFriends[i], currentMax1);

			}
		}
		/**/
		int ttt= n[f];
		for (int s = 0;s < ttt;s++){
			int low = 0;
			int high = m[f] - 1;
			while (high >= low){
				int mid = (low + high)/2;
				if(strcmp (friends[s] , sentFriends[mid]) < 0)
					high = mid - 1;
				else if (strcmp (friends[s] , sentFriends[mid]) == 0)
				{
					n[f] = n[f] - 1;
					break;
				}
				else
					low = mid + 1;
			}
		}
		y += 1;
	}
	for (int d = 0;d < y;d++)
		cout<<n[d]<<endl;

	return 0;
}



