/*
ID: silasli2
PROG: stamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

inline int min2(int a, int b){
    if (a<b) return a;
    else return b;
}
const int Max = 2000000;
int dp[Max],values[50];
int main() {
    ofstream fout ("stamps.out");
    ifstream fin ("stamps.in");



    int K, N;
    fin>>K>>N;
    for (int i=0;i<N;i++){
        fin>>values[i];
    }
    dp[0]=0;
    for (int i=1;i<Max;i++){
        dp[i] = 1000;
    }
    int ans=0;
    while (true){
        ans++;
        for (int i=0;i<N;i++){
            if (ans-values[i]>=0 && dp[ans-values[i]]<=K-1){
                dp[ans] = min2(dp[ans], dp[ans-values[i]]+1);
            }
        }
        if (dp[ans]==1000){
            ans--;
            break;
        }

    }
    cout<<ans<<endl;
    fout<<ans<<endl;
    return 0;
}
