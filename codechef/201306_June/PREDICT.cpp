#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

double solve(double p){
    if (p<0.5) p = 1-p;
    return p*(10000 + 10000*2*(1-p));
}

int main(){
    //freopen("PREDICT.in", "r", stdin);
    int T;
    cin>>T;
    while (T--){
        double p;
        cin>>p;
        printf("%.6lf\n",solve(p));
    }
    return 0;
}
