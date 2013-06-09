/*
ID: silasli2
PROG: inflate
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int max2(int a, int b){
    if (a>b){
        return a;
    }else{
        return b;
    }
}
int main() {
    ofstream fout ("inflate.out");
    ifstream fin ("inflate.in");
    int space, n;
    const int spaceMax = 10000;
    const int N = 10000;
    fin>>space>>n;
    int value[N];
    int cost[N];
    for (int i = 0;i<n;i++){
        fin>>value[i]>>cost[i];
    }
    int dp[spaceMax+1];
    for (int i =0;i<=spaceMax;i++){
        dp[i] = 0;
    }
    for (int i =0;i<=space;i++){
        for (int j = 0;j<n;j++){
            if (i-cost[j]>=0){
                dp[i] = max2(dp[i], dp[i-cost[j]]+value[j]);
            }
        }
    }
    cout<<dp[space]<<endl;
    fout<<dp[space]<<endl;

    return 0;
}
