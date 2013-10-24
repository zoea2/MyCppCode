#include <iostream>
using namespace std;

int main() {
    int L, C, N, i;
    cin >> L >> C >> N;

    for (i = 0; i < C; i++) {
        int Si, Pi, location;
        cin >> Si >> Pi;
        if (Pi > N) {
            location = Pi - N + Si;
        }
        else {
            location = N - Pi + Si;
        }

        cout << location << endl;
    }


    return 0;
}
