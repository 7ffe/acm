/*
ID: silasli2
PROG: heritage
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
ofstream fout ("heritage.out");
ifstream fin ("heritage.in");

string in_order_str, pre_order_str, post_str;
int len;

int init(){
    fin>>in_order_str>>pre_order_str;
    len = in_order_str.length();
    cout<<len<<endl;
    return 0;
}

string post(int in_1, int in_2, int pre_1, int pre_2){
    if (in_1 > in_2){return "";}
    char mid = pre_order_str[pre_1];
    int p_mid = in_1;
    while (in_order_str[p_mid]!=mid) p_mid++;
    cout<<p_mid<<endl;
    int len1 = p_mid - in_1;
    int len2 = in_2 - p_mid;
    return post(in_1, p_mid-1, pre_1+1,  pre_1 + len1) + post(p_mid+1, in_2, pre_1+len1+1, pre_2) + mid;
}

int solve(){
    post_str = post(0, len-1, 0, len-1);
    return 0;
}
int output(){
    cout<<post_str<<endl;
    fout<<post_str<<endl;
    return 0;
}

int main() {
    init();
    solve();
    output();
    return 0;
}
