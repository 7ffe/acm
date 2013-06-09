/*
ID: silasli2
PROG: rockers
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
ofstream fout ("rockers.out");
ifstream fin ("rockers.in");

int N, T, M, a[20];
int ans;

int init(){
    fin>>N>>T>>M;
    for (int i = 0;i< N;i++){
        fin>>a[i];
    }
    return 0;
}

int max(int a, int b){
    return a>b?a:b;
}

int solve(){
    int dp[21][21];
    memset(dp, 0, sizeof(int) * 21*21);
    for (int i = 0; i<N;i++){
        for (int j=M;j>=1;j--){
            for (int k = T;k>=0;k--){
                //1. discard song i, remain dp[j][k]
                //2. record song i on disk j
                if (k>=a[i]){
                    dp[j][k] = max(dp[j][k], dp[j][k-a[i]]+1);
                }else if (j>1 && T>=a[i]){
                //3. record song i on disk j-1
                    dp[j][k] = max(dp[j][k], dp[j-1][T-a[i]]+1);
                }
            }
        }
    }
    ans = dp[M][T];
    return 0;
}
int output(){
    cout<<ans<<endl;
    fout<<ans<<endl;
    return 0;
}

int main() {
    init();
    solve();
    output();
    return 0;
}
