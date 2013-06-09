#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
int main(){
    //freopen("B.in", "r", stdin);
    //cout<<pow(0.5, 3.0)<<endl;
    //cout<<fabs(-0.1)<<endl;
    int n, a, b, c, d;
    cin>> a>>b>>c>>d;
    double p1 = 1.0*a/b;
    double p2 = 1.0*c/d;
    n=1;
    while (fabs( pow((1-p1)*(1-p2), n)  - pow((1-p1)*(1-p2), n+1) )>0.00000001)
        n++;
    double sum = 0, tmp=1.0;
    for (int i=0;i<n;i++){
        sum += tmp*p1;
        tmp *= (1-p1)*(1-p2);
    }
    printf("%.8lf\n", sum);
}
