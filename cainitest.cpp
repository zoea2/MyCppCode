#include <iostream>
using namespace std;

int main() {
    int x,y;
    cin >> x >> y;
    int array[x];
    int length = 0;
    for(int i = 1; i <= x; ++i) {
        if(x % i== 0) {
            array[length] = i;
            ++ length;
        }
    }
    for(int j = 0; j < length; ++j) {
        for(int k = 1; k <= y; ++k) {
            cout << array[j] << " " << k << endl;
        }
    }
}
