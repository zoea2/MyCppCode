// source code of submission 1061506, Zhongshan University Online Judge System
#include <stdio.h>

#define MAX 10
int used[MAX];
int result[MAX];
int N;

void print(){
int i;
for(i = 0; i < N; i++)
if(i < N - 1)
printf("%d ", result[i]);
else
printf("%d\n",result[i]);
}
void proc(int step){
int i;
if(step == N)
print();
else{
for(i = 0; i < N; i++){
if(!used[i]){
used[i] = 1;
result[step] = i + 1;
proc(step + 1);
used[i] = 0;
}
}
}
}

int main(){
    int t;
    scanf("%d",&t);
    while (t)
    {
        t--;
        scanf("%d", &N);
        proc(0);
    }

}
