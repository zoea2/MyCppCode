#include <iostream>
using namespace std;
int main()
{
	int temp = 0;
	_asm inc temp;
	temp++;
	cout<<temp<<endl;
	system("pause");
}
