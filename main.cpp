#include <iostream>

using namespace std;

int main()
{
    wchar_t c[] = L"Hello world!" ;
    cout << sizeof(c)<<" "<<c<< endl;
    return 0;
}
