#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main(){
    freopen("A.in", "r", stdin);
    char line[200];
    int n;
    cin>>n;
    cin.getline(line, 200);
    while (n--){
        cin.getline(line, 200);
        //cout<<line<<endl;
        int len = strlen(line);
        //cout<<line[len-1]<<endl;
        bool A = false, B = false;
        if (len>=5 && line[0]=='m' && line[1]=='i' && line[2]=='a' && line[3]=='o' && line[4]=='.')
            A = true;

        if (len>=5 && line[len-5]=='l' && line[len-4]=='a' && line[len-3]=='l' && line[len-2]=='a' && line[len-1]=='.')
            B = true;
        if (A && !B)
            cout<<"Rainbow's"<<endl;
        else if (!A && B)
            cout<<"Freda's"<<endl;
        else cout<<"OMG>.< I don't know!"<<endl;
    }
}
