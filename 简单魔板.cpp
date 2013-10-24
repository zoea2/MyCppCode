#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
struct step {
    int status[8];
    string steps;
};
int target[8];
const int init[8] = {1, 2, 3, 4, 8, 7, 6, 5};
int maxStep;
void A(queue<step> &q, const step statu) {
    step tmp;
    for(int i = 0; i < 4; i++) {
        tmp.status[i] = statu.status[i + 4];
        tmp.status[i + 4] = statu.status[i];
    }
    tmp.steps = statu.steps + 'A';
    q.push(tmp);
}
void B(queue<step>& q, const step& statu) {
    step tmp;
    for(int i = 1; i < 4; i++) {
        tmp.status[i] = statu.status[i - 1];
        tmp.status[i + 4] = statu.status[i - 1 + 4];
    }
    tmp.status[0] = statu.status[3];
    tmp.status[4] = statu.status[7];
    tmp.steps = statu.steps + 'B';
    q.push(tmp);
}
void C(queue<step>& q, const step& statu) {
    step tmp;
    tmp.status[0] = statu.status[0];
    tmp.status[1] = statu.status[5];
    tmp.status[2] = statu.status[1];
    tmp.status[3] = statu.status[3];
    tmp.status[4] = statu.status[4];
    tmp.status[5] = statu.status[6];
    tmp.status[6] = statu.status[2];
    tmp.status[7] = statu.status[7];
    tmp.steps = statu.steps + 'C';
    q.push(tmp);
}
void bfs() {
    queue<step> q;
    step tmp;
    memcpy(tmp.status, init, sizeof(init));
    q.push(tmp);
    while(!q.empty()) {
        tmp = q.front();
        q.pop();
        if(memcmp(tmp.status, target, sizeof(target)) == 0) {
            cout << tmp.steps.size() << " " << tmp.steps << endl;
            return;
        }
        if(tmp.steps.size() == maxStep) {
            continue;
        }
        A(q, tmp);
        B(q, tmp);
        C(q, tmp);
    }
    cout << -1 << endl;
}
int main() {
    cin >> maxStep;
    while(maxStep != -1) {
        for(int i = 0; i < 8; i++) {
            cin >> target[i];
        }
        bfs();
        cin >> maxStep;
    }
    return 0;
}
