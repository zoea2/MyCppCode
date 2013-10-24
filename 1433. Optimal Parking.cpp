#include "iostream"
#include "algorithm"
using namespace std;
int main()
{
	int TestCase;
	cin >> TestCase;
	while (TestCase--)
	{
		int StoreNum, distance = 0;
		cin >> StoreNum;
		int *pos = new int[StoreNum];
		for (int i = 0; i < StoreNum; i++)
			cin >> pos[i];
		sort(pos, pos+StoreNum);
		distance = pos[StoreNum-1] - pos[0];
		cout << distance*2 << endl;
	}
}
