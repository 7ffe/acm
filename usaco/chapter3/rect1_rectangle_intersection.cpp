/*
ID: silasli2
PROG: rect1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>
using namespace std;
const int NM=1001;
int A,B,N;
int x1[NM], y1[NM], x2[NM], y2[NM];
int RecIntSec(int layer, int xx1, int yy1, int xx2, int yy2){
    int ans=0;
    int n=N;
    while (layer<=n && ((x1[layer]>=xx2)||(x2[layer]<=xx1)||(y1[layer]>=yy2)||(y2[layer]<=yy1))){
        layer++;
    }
    if (layer>n){
        return (xx2-xx1)*(yy2-yy1);
    }
    if (y1[layer]>yy1){
        ans += RecIntSec(layer+1, xx1, yy1, xx2, y1[layer]);
        yy1=y1[layer];
    }
    if (y2[layer]<yy2){
        ans += RecIntSec(layer+1, xx1, y2[layer], xx2, yy2);
        yy2=y2[layer];
    }
    if (x1[layer]>xx1){
        ans += RecIntSec(layer+1, xx1, yy1, x1[layer], yy2);
        xx1=x1[layer];
    }
    if (x2[layer]<xx2){
        ans += RecIntSec(layer+1, x2[layer], yy1, xx2, yy2);
    }
    return ans;
}

int main() {
    ofstream fout ("rect1.out");
    ifstream fin ("rect1.in");

    fin>>A>>B>>N;
    int colors[NM];
    for (int i =0;i<N;i++){
        fin>>x1[i]>>y1[i]>>x2[i]>>y2[i]>>colors[i];
    }
    const int CM=2500;
    int count[CM+1];
    memset(count, 0, sizeof(int)*(CM+1));

    for (int i=N-1;i>=0;i--){
        count[colors[i]] += RecIntSec(i+1,x1[i], y1[i], x2[i], y2[i]);
    }
    int total=0;
    for (int i=2;i<=CM;i++){
        total += count[i];
    }
    count[1] = A*B-total;
    for (int i=1;i<=CM;i++){
        if (count[i]>0){
            cout<<i<<' '<<count[i]<<endl;
            fout<<i<<' '<<count[i]<<endl;
        }
    }
    return 0;
}

