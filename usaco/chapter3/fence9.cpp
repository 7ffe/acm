/*
ID: silasli2
PROG: fence9
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
ofstream fout ("fence9.out");
ifstream fin ("fence9.in");

int n, m, p;
int ans;

int init(){
    fin>>n>>m>>p;
    ans = 0;
    return 0;
}

int left(double r){
    return int(r) + 1;
}
double abs(double r){
    return r>0?r:-r;
}
int right(double r){
    int n = int (r);
    return abs(n-r)<0.00000001?(n-1):n;
}
int solve(){
    double l1 = n;
    double l2 = p-l1;
    for (int i = 1;i<m;i++){
        double h = m- 1.0*i;
        double k1 = h*l1/m;
        double k2 = h*l2/m;
        double x1 = l1-k1;
        double x2 = l1+k2;
        ans += right(x2) - left(x1)+1;
        //cout<<x1<<'\t'<<x2<<'\t'<<right(x2) - left(x1)+1<<endl;
    }

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
