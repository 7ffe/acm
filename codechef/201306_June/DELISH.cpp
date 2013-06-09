#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

const int N = 20000;
long long d[N], minL[N], minR[N], maxL[N], maxR[N];
long long mminL[N], mminR[N], mmaxL[N], mmaxR[N];

/*long long abs(long long n){
    return n>0?n:(-n);
}*/
long long max(long long a, long long b){
    if (a>b) return a;
    else return b;
}
long long min(long long a, long long b){
    if (a<b) return a;
    else return b;
}
long long labs(long long n){
    if (n<0) return 0LL-n;
    else return n;
}

int solve(int n){
    minL[0] = d[0];
    maxL[0] = d[0];
    mminL[0] = d[0];
    mmaxL[0] = d[0];
    /*for (int i=0;i<n;i++)
        cout<<d[i]<<' ';
    cout<<endl;*/
    for (int i=1;i<n;i++){
        if (minL[i-1]<0) minL[i] = minL[i-1] + d[i];
        else minL[i] = d[i];
        mminL[i] = min(minL[i], mminL[i-1]);

        if (maxL[i-1]>0) maxL[i] = maxL[i-1] + d[i];
        else maxL[i] = d[i];
        mmaxL[i] = max(maxL[i], mmaxL[i-1]);
    }
    minR[n-1] = d[n-1];
    maxR[n-1] = d[n-1];
    mminR[n-1] = d[n-1];
    mmaxR[n-1] = d[n-1];
    for (int i=n-2;i>=0;i--){
        if (minR[i+1]<0) minR[i] = minR[i+1] + d[i];
        else minR[i] = d[i];
        mminR[i] = min(minR[i], mminR[i+1]);

        if (maxR[i+1]>0) maxR[i] = maxR[i+1] + d[i];
        else maxR[i] = d[i];
        mmaxR[i] = max(maxR[i], mmaxR[i+1]);
    }
    long long ans = labs(mminL[0] - mmaxR[1]);
    for (int i=1;i<n;i++){
        ans = max(ans, labs(mminL[i-1]-mmaxR[i]));
        ans = max(ans, labs(mmaxL[i-1]-mminR[i]));
    }
    cout<<ans<<endl;
    return ans;
}
void clean(){
    memset(mminL, 0, sizeof(long long)*N);
    memset(mminR, 0, sizeof(long long)*N);
    memset(mmaxL, 0, sizeof(long long)*N);
    memset(mmaxR, 0, sizeof(long long)*N);
    memset(minL, 0, sizeof(long long)*N);
    memset(minR, 0, sizeof(long long)*N);
    memset(maxL, 0, sizeof(long long)*N);
    memset(maxR, 0, sizeof(long long)*N);
}
int main(){
    freopen("DELISH.in", "r", stdin);
    int T;
    cin>>T;
    while (T--){
        clean();
        int n;
        cin>>n;
        for (int i=0;i<n;i++)
            cin>>d[i];
        solve(n);
    }
    /*long long a, b;
    a = -23894728975893745;
    b =  -23987398457938475;
    cout<<a+b<<endl;*/
    return 0;
}
