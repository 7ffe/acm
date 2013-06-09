#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

bool isSquare(int n){
    int a = int(sqrt(n));
    return n == a*a;
}

int main(){
    int N, a,b,c, cnt=0;
    cin>>N;
    a = 1;
    while (a<=N){
        b = a;
        while (b<=N && a*a+b*b<=N*N){
            if (isSquare(a*a+b*b)) cnt++;
            b++;
        }
        a++;
    }
    cout<<cnt<<endl;
    return 0;
}
