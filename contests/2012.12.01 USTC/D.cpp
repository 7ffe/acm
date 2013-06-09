#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    freopen("D.txt", "r", stdin);

    int N, K;
    double func[1001];
    while (scanf("%d%d", &N, &K)!=EOF){

        func[0] = 0.0;
        func[1] = 0.0;
        for (int n=2;n<=N;n++){
            func[n] =0.0;
            for (int x = 1;x<=n-1;x++){
                func[n] += (0- x*x+n*x + K  + func[x] + func[n-x])*1.0/(n-1);
            }

        }
        cout<<(long long)(func[N])<<endl;
    }



}
