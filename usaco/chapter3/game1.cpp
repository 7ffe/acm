/*
ID: silasli2
PROG: game1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
ofstream fout ("game1.out");
ifstream fin ("game1.in");

int n;
int data[100];
int done[100][100];
int dp[100][100];
int sum[100][100];


int init(){
    fin>>n;
    for (int i=0;i<n;i++)
        fin>>data[i];
    for (int i=0;i<n;i++){
        sum[i][i] = data[i];
        for (int j=i+1;j<n;j++)
            sum[i][j] = sum[i][j-1] + data[j];
    }
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++){
            done[i][j] =0;
            dp[i][i] = 0;
        }
    return 0;
}
int max2(int a, int b){
    if (a>b) return a;
    return b;
}
int DP(int left, int right){
    if (done[left][right]==1){
        return dp[left][right];
    }
    if (left == right){
        done[left][right] = 1;
        dp[left][right] = data[left];
        return dp[left][right];
    }

    dp[left][right] =  max2(data[left] -DP(left+1, right) + sum[left+1][right],  data[right]-DP(left, right-1)+sum[left][right-1]);
    done[left][right] =1;
    return dp[left][right];


}
int solve(){
    DP(0, n-1);
    return 0;
}
int output(){
    cout<<dp[0][n-1]<<' '<<sum[0][n-1]-dp[0][n-1]<<endl;
    fout<<dp[0][n-1]<<' '<<sum[0][n-1]-dp[0][n-1]<<endl;
    return 0;
}

int main() {
    init();
    solve();
    output();
    return 0;
}
