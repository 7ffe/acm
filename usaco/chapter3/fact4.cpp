/*
ID: silasli2
PROG: fact4
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("fact4.out");
    ifstream fin ("fact4.in");
    int n;
    fin >> n;
    int five = 0;
    int two =0;
    int m;
    int fivepower=5;
    while (n>=fivepower){
        five += n/fivepower;
        fivepower*=5;
    }
    two =five;

    int ans =1;
    for (int i=2;i<=n;i++){
        m=i;
        while (two>0 && m%2==0){
            m/=2;
            two--;
        }
        while (five>0 && m%5==0){
            m/=5;
            five--;
        }
        ans = (ans*m)%10;
    }
    cout<<ans<<endl;
    fout<<ans<<endl;
    return 0;
}
