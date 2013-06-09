#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main(){
    int n, k;
    cin>>n>>k;
    int tot;
    tot = n*(n-1)/2;
    if (tot>k){
        int t = 0;
        for (int i=0;i<n;i++)
            cout<<0<<' '<<t++<<endl;

    }else{
        cout<<"no solution"<<endl;
    }
}
