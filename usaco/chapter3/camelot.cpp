/*
ID: silasli2
PROG: camelot
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
ofstream fout ("camelot.out");
ifstream fin ("camelot.in");

const int M_R = 30, M_C = 26;
int g[M_R][M_C][M_R][M_C];

int done[M_R][M_C];
int qr, qc;
int kr[10000], kc[10000], knum;

int xque[30*260];
int yque[30*260];
int pos, que_end;

int move_x[] = {2,2,-2,-2,1,1,-1,-1};
int move_y[] = {1,-1,-1,1,2,-2,-2,2};

int R, C;

int init(){
    fin>>R>>C;
    string tmp;
    int t;
    fin>>tmp>>t;
    qr = t-1; qc = tmp[0]-'A';

    knum =0;
    while (fin>>tmp>>t){
        kr[knum] = t-1;
        kc[knum++] = tmp[0]-'A';
    }
    for (int r1 =0;r1<R;r1++)
        for (int c1=0;c1<C;c1++)
            for (int r2 =0;r2<R;r2++)
                for (int c2=0;c2<C;c2++)
                    g[r1][c1][r2][c2] = 2000000;
    return 0;
}

int intabs(int n){
    if (n>=0) return n;
    return -n;
}
int queendist(int r,int c){
    return intabs(r-qr)>intabs(c-qc)?intabs(r-qr):intabs(c-qc);
}
int spfa(){
    int max = 0;
    for (int r1=0;r1<R;r1++)
        for (int c1=0;c1<C;c1++){
            memset(done, 0, sizeof(int)*M_R*M_C);
            pos = 0;
            que_end = 0;
            xque[pos] = r1; yque[pos] = c1;
            done[r1][c1] = 1;
            g[r1][c1][r1][c1]=0;
            while (pos<=que_end){
                int r,c;
                r = xque[pos];
                c = yque[pos];

                //g[r][c][r1][c1]=0;
                for (int i=0;i<8;i++){
                    int _r,_c;
                    _r = r+move_x[i];
                    _c = c+move_y[i];
                    //cout<<_r<<' '<<_c<<endl;
                    if ((_r>=0 && _r<R && _c>=0 && _c<C)
                        && done[_r][_c]==0){
                        g[r1][c1][_r][_c] = g[r1][c1][r][c] + 1;
                        if (g[r1][c1][_r][_c]>max) max = g[r1][c1][_r][_c];
                        done[_r][_c] = 1;
                        xque[++que_end] = _r;
                        yque[que_end] = _c;

                    }
                }
                pos++;
            }

        }
    //cout<<'='<<max<<endl;

}
int min_answer = 200000000;
int solve(){
    if (knum==0){
        min_answer =0;
        return 0;
    }
    for (int gather_r = 0; gather_r < R;gather_r++)
        for (int gather_c =0; gather_c < C;gather_c++){
            int res = 0;
            for (int i=0;i<knum;i++){
                res += g[gather_r][gather_c][kr[i]][kc[i]];
                //cout<<res<<endl;
            }
            if (res>min_answer) continue;
            for (int carry_r = 0;carry_r<R; carry_r++)
                for (int carry_c = 0;carry_c<C;carry_c++)
                    for (int k =0;k<knum;k++){
                        int res_ans =res;
                        res_ans -= g[gather_r][gather_c][kr[k]][kc[k]];
                        res_ans += g[carry_r][carry_c][kr[k]][kc[k]];
                        res_ans += queendist(carry_r, carry_c);
                        res_ans += g[carry_r][carry_c][gather_r][gather_c];
                        if (res_ans<min_answer){
                            min_answer = res_ans;
                        }
                    }
        }

    return 0;
}
int output(){
    cout<<min_answer<<endl;
    fout<<min_answer<<endl;
    return 0;
}

int main() {
    init();
    spfa();
    solve();
    output();
    return 0;
}
