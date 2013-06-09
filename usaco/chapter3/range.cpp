/*
ID: silasli2
PROG: range
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
ofstream fout ("range.out");
ifstream fin ("range.in");

string map[250];
int dp[250][250];
int n;
int count[251];


int init(){
    memset(count, 0, sizeof(int)*251);
    fin>>n;
    for (int i=0;i<n;i++)
        fin>>map[i];
    /*
    for (int i=0;i<n;i++)
        cout<<map[i]<<endl;
    cout<<n<<endl;*/

    return 0;
}
int isOne(char c){
    if (c=='1') return 1;
    return 0;
}
int min2(int a, int b){
    if (a<b) return a;
    return b;
}

int solve(){
    dp[0][0] = isOne(map[0][0]);
    for (int i=1;i<n;i++){
        dp[0][i] = isOne(map[0][i]);
        dp[i][0] = isOne(map[i][0]);
    }
    for (int i=1;i<n;i++)
        for (int j=1;j<n;j++){
            if (map[i][j]=='0'){
                dp[i][j] = 0;
            }else{
                int res = dp[i-1][j-1];
                res = min2(res, dp[i-1][j]);
                res = min2(res, dp[i][j-1]);
                dp[i][j] = res+1;
            }
        }

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++){
            count[dp[i][j]]++;
        }
    for (int i=n-1;i>=1;i--)
        count[i] += count[i+1];
    return 0;
}
int output(){
    //cout<<count[2]<<endl;
    for (int i=2;i<=n;i++)
        if (count[i]>0){
            cout<<i<<' '<<count[i]<<endl;
            fout<<i<<' '<<count[i]<<endl;
        }
    return 0;
}

int main() {
    init();
    solve();
    output();
    return 0;
}
