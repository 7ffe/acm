/*
ID: silasli2
PROG: shopping
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
ofstream fout ("shopping.out");
ifstream fin ("shopping.in");


int codeToId[1000];

int s,b;
int _num[100], _c[100][5], _k[100][5];
int deals[100+5][6], deals_price[100+5];
int need[6], price[6];
int dp[6][6][6][6][6];


int init(){
    memset(dp, 0,sizeof(int)*6*6*6*6*6);

	fin>>s;
	memset(deals_price, 0, sizeof(int)*105);
	for (int i=0;i<s;i++){
	    fin>>_num[i];
	    for (int j=0;j<_num[i];j++)
            fin>>_c[i][j]>>_k[i][j];
        fin>>deals_price[i];
	}
    memset(need, 0, sizeof(int)*6);
    memset(price, 0, sizeof(int)*6);

    memset(codeToId, 0, sizeof(int)*1000);


    fin>>b;
    for (int i=1;i<=b;i++){
        int c,k,p;
        fin>>c>>k>>p;
        codeToId[c]=i;
        need[i]=k;
        price[i]=p;
    }

    memset(deals, 0, sizeof(int)*105*6);

    for (int i=0;i<s;i++){
        deals[i][0] = _num[i];
        for (int j=0;j<_num[i];j++){
            deals[i][codeToId[_c[i][j]]] = _k[i][j];
        }

    }
    for (int i=s;i<s+b;i++){
        deals[i][i-s+1] = 1;
        deals_price[i] = price[i-s+1];
    }
    return 0;
}
int solve(){
    //dynamic programming
    int i1,i2,i3,i4,i5;
    int BigCost = 9999*25*10;
    for (i1=0;i1<=need[1];i1++)
        for (i2=0;i2<=need[2];i2++)
            for (i3=0;i3<=need[3];i3++)
                for (i4=0;i4<=need[4];i4++)
                    for (i5=0;i5<=need[5];i5++)
                        dp[i1][i2][i3][i4][i5] = BigCost;
    dp[0][0][0][0][0]=0;
    for (i1=0;i1<=need[1];i1++)
        for (i2=0;i2<=need[2];i2++)
            for (i3=0;i3<=need[3];i3++)
                for (i4=0;i4<=need[4];i4++)
                    for (i5=0;i5<=need[5];i5++){
                        for (int d=0;d<s+b;d++){
                            if ((i1>=deals[d][1] && i2>=deals[d][2] && i3>=deals[d][3] && i4>=deals[d][4] && i5>=deals[d][5])
                                &&(dp[i1][i2][i3][i4][i5] > dp[i1-deals[d][1]][i2-deals[d][2]][i3-deals[d][3]][i4-deals[d][4]][i5-deals[d][5]] + deals_price[d])){
                                    dp[i1][i2][i3][i4][i5] = dp[i1-deals[d][1]][i2-deals[d][2]][i3-deals[d][3]][i4-deals[d][4]][i5-deals[d][5]] + deals_price[d];
                                }
                        }


                    }

    return 0;
}
int output(){
    cout<<dp[need[1]][need[2]][need[3]][need[4]][need[5]]<<endl;
    fout<<dp[need[1]][need[2]][need[3]][need[4]][need[5]]<<endl;
    return 0;
}

int main() {
    init();
    solve();
    output();
    return 0;
}
