/*
ID: silasli2
PROG: nuggets
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>

using namespace std;
ofstream fout ("nuggets.out");
ifstream fin ("nuggets.in");

int N;
vector<int> box;

int gcd(int a, int b){
    if (b==0) return a;
    else return gcd(b, a%b);
}

int lcm(int a, int b){
    return a/gcd(a,b)*b;
}

int init(){
    fin>>N;
    int tmp;
    for (int i=0;i<N;i++){
        fin>>tmp;
        box.push_back(tmp);
    }
    sort(box.begin(), box.end());
    //cout<<box.size()<<endl;


    return 0;
}
int ans;
int lcm_all = 20000000;
vector<bool> check(lcm_all, false);
int min;

int solve(){
    int gcd_all = box[0];
    for (int i=1;i<box.size();i++)
        gcd_all = gcd(gcd_all, box[i]);
    cout<<gcd_all<<endl;
    if (gcd_all!=1){
        return 0;
    }
    else{
        int min = box[0];
        for (int i=1;i<N;i++){
            if (min>box[i]){
                min = box[i];
            }
        }
        /*
        int lcm_all = box[0];
        for (int i=1;i<N;i++){
            lcm_all = lcm(lcm_all, box[i]);
            cout<<i<<"\tlcm so far: "<<lcm_all<<endl;

        }
        cout<<"lcm_all is "<<lcm_all<<endl;
        */

        check[0] = 1;
        int count =0;
        for (int i=0;i<check.size(); i++){
            if (check[i]){
                count++;
                if (count==min)
                    if (count==i+1)
                        return 0;
                    else
                        return i-min;
            }else{
                count=0;
            }
            for (int j=0;j<box.size();j++){
                if (check[i] && i+box[j]<check.size()){
                    check[i+box[j]] = 1;
                }
            }
        }
        ans = check.size()-1;
        check[0] =0;
        while (check[ans]) ans--;
        return ans;
    }
}
int output(){
    cout<<ans<<endl;
    fout<<ans<<endl;
    return 0;
}

int main() {
    init();
    ans = solve();
    output();
    return 0;
}
