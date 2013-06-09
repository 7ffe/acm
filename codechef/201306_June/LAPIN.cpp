#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
bool check(string s){
    int len = s.size();
    map<char, int> cnt1, cnt2;
    int i,j;
    for (i=0;i<len;i++){
        cnt1[s[i]] = 0;
        cnt2[s[i]] = 0;
    }
    i=0, j = len-1;
    while (i<j){
        cnt1[s[i]] = cnt1[s[i]] + 1;
        cnt2[s[j]] = cnt2[s[j]] + 1;
        i++;
        j--;
    }
    for (i=0;i<len;i++)
    if (cnt1[s[i]] != cnt2[s[i]]){
        return false;
    }
    return true;
}
int main(){
    freopen("LAPIN.in", "r", stdin);
    int T;
    cin>>T;
    while (T--){
        string s;
        cin>>s;
        if (check(s))
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
