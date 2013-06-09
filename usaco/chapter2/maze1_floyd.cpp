/*
ID: silasli2
PROG: maze1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int min2(int a ,int b){
    if (a<b){
        return a;
    }else{
        return b;
    }
}
int max2(int a ,int b){
    if (a<b){
        return b;
    }else{
        return a;
    }
}
const int W_Max = 38, H_Max = 100;
const int HW_Max = H_Max * W_Max;
const int distMax = H_Max*W_Max*2;
short int dist[H_Max*W_Max][H_Max*W_Max];
short int path[H_Max*W_Max][H_Max*W_Max];
ofstream fout ("maze1.out");
ifstream fin ("maze1.in");

int printGrid(int data[][HW_Max], int h, int w){
    for (int i = 0;i<h;i++){
        for (int j = 0;j<w;j++){
            fout<<data[i][j]<<' ';
        }
        fout<<endl;
    }
}
int main() {


    int W, H;
    char tmp, tmpL[10];
    //1<=W<=38
    fin >> W >> H;
    fin.getline(tmpL, 10);
    char oldMap[2*H_Max+1][2*W_Max+1];
    for (int i = 0; i< 2*H+1; i++){
        fin.getline(oldMap[i],2*W+2);
    }

    //fout<<W<<' '<<H<<endl;
    for (int i = 0; i< 2*H+1; i++){
        //fout<<oldMap[i]<<endl;
    }


    for (int i = 0; i< H_Max*W_Max; i++){
        for (int j = 0; j<H_Max*W_Max; j++){
            dist[i][j] = distMax;//initialize to very large
            path[i][j] = distMax;
        }
        dist[i][i] = 0;
        path[i][i] = 0;
    }

    //Build the dist table
    for (int i = 0; i<H;i++){
        for (int j = 0; j<W;j++){
            //to its right

            int i2 = i;
            int j2 = j+1;
            if (j2<W){
                if (oldMap[2*i+1][2*j+1+1]==' '){//connect to the right block
                    dist[i*W+j][i2*W+j2] = 1;
                    dist[i2*W+j2][i*W+j] = 1;
                }
            }
            //to its bottom
            i2 = i+1;
            j2 = j;
            if (i2<H){
                if (oldMap[2*i+1+1][2*j+1]==' '){
                    dist[i*W+j][i2*W+j2] = 1;
                    dist[i2*W+j2][i*W+j] = 1;
                }
            }
        }
    }
    //printGrid(dist, H*W, H*W);
    //Find the exits
    int eid1 = -1, eid2=-1;
    for (int i = 0;i<H;i++){
        int j = 0;
        if (oldMap[2*i+1][2*j+1-1]==' '){
            if (eid1==-1){
                eid1 = i*W+j;
            }
            else{
                eid2 = i*W+j;
            }
        }
        j = W-1;
        if (oldMap[2*i+1][2*j+1+1]==' '){
            if (eid1==-1){
                eid1 = i*W+j;
            }
            else{
                eid2 = i*W+j;
            }
        }
    }
    for (int j = 0;j<W;j++){
        int i = 0;
        if (oldMap[2*i+1-1][2*j+1]==' '){
            if (eid1==-1){
                eid1 = i*W+j;
            }
            else{
                eid2 = i*W+j;
            }
        }
        i = H-1;
        if (oldMap[2*i+1+1][2*j+1]==' '){
            if (eid1==-1){
                eid1 = i*W+j;
            }
            else{
                eid2 = i*W+j;
            }
        }
    }

    //Floyd
    for (int k = 0; k<H*W;k++){
        for (int i = 0; i<H*W;i++){
            for (int j = 0; j<H*W;j++){
                if (dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    int distL[HW_Max];
    for (int i = 0; i< H*W; i++){
        distL[i]=min2(dist[i][eid1],dist[i][eid2]);
    }
    int res = 0;
    for (int i = 0;i<H*W;i++){
        if (distL[i]==distMax){
            continue;
        }
        res = max2(res, distL[i]);
    }
    fout<<res+1<<endl;
    return 0;

}
