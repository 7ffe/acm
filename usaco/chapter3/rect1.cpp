/*
ID: silasli2
PROG: rect1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
    return 0;
}

int quicksort(int data[], int head, int tail){
    if (head>=tail){
        return 0;
    }
    int p = (head+tail)/2;
    int midv = data[p];
    swap(data[p], data[tail]);
    int store = head;
    for (int i = head; i<=tail-1;i++){
        if (data[i]<midv){
            swap(data[i], data[store]);
            store++;
        }
    }
    swap(data[store], data[tail]);

    quicksort(data, head, store-1);
    quicksort(data, store+1, tail);
    return 0;
}

int contains(int data[], int len, int n){
    for (int i =0;i<len;i++){
        if (data[i]==n){
            return 1;
        }
    }
    return 0;
}
int colors[2*(1000+1)][2*(1000+1)];
int main() {
    ofstream fout ("rect1.out");
    ifstream fin ("rect1.in");
    int A,B,N;
    fin>>A>>B>>N;
    int stat[1000][5];
    int xcors[2000+10];
    int ycors[2000+10];
    int xmap[2000+10];
    int ymap[2000+10];
    xcors[0]=0;
    xcors[1]=A;
    ycors[0]=0;
    ycors[1]=B;
    int xLen=2;
    int yLen=2;
    for (int i =0;i<N;i++){
        for (int j =0;j<5;j++){
            fin>>stat[i][j];
        }
        if (!contains(xcors, xLen, stat[i][0])){
            xcors[xLen++]=stat[i][0];
        }
        if (!contains(xcors, xLen, stat[i][2])){
            xcors[xLen++]=stat[i][2];
        }
        if (!contains(ycors, yLen, stat[i][1])){
            ycors[yLen++]=stat[i][1];
        }
        if (!contains(ycors, yLen, stat[i][3])){
            ycors[yLen++]=stat[i][3];
        }
    }
    /*
    for (int i =0;i<xLen;i++){
        cout<<xcors[i]<<" ";
    }
    cout<<endl;
    for (int i =0;i<yLen;i++){
        cout<<ycors[i]<<" ";
    }
    cout<<endl;*/
    quicksort(xcors,0,xLen-1);
    quicksort(ycors,0,yLen-1);

    for (int i =0;i<xLen;i++){
        cout<<xcors[i]<<" ";
    }
    cout<<endl;
    for (int i =0;i<yLen;i++){
        cout<<ycors[i]<<" ";
    }
    cout<<endl;

    //build map

    for (int i =0;i<xLen;i++){
        xmap[xcors[i]]=i;
        cout<<xmap[xcors[i]]<<" "<<xcors[i]<<endl;
    }
    cout<<endl;
    for (int i =0;i<yLen;i++){
        ymap[ycors[i]]=i;
        cout<<ymap[ycors[i]]<<' '<<ycors[i]<<endl;
    }
    cout<<endl;

    const int tmp=2*1001;

    for (int i=0;i<tmp;i++){
        for (int j=0;j<tmp;j++)
            colors[i][j]=1;
    }

    for (int i =0;i<N;i++){
        int x1=xmap[stat[i][0]];
        int x2=xmap[stat[i][2]];
        int y1=ymap[stat[i][1]];
        int y2=ymap[stat[i][3]];

        for (int ix=x1;ix<x2;ix++){
            for (int iy=y1;iy<y2;iy++){
                colors[ix][iy]=stat[i][4];
            }

        }
        cout<<'('<<x1<<','<<y1<<")  ("<<x2<<','<<y2<<")"<<endl;
        for (int i=yLen-2;i>=0;i--){
        for (int j=0;j<xLen-1;j++){
            cout<<colors[j][i]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
    }


    for (int i=yLen-2;i>=0;i--){
        for (int j=0;j<xLen-1;j++){
            cout<<colors[j][i]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;

    int count[2501];
    for (int i=0;i<2501;i++){
        count[i]=0;
    }
    for (int i=0;i<xLen-1;i++){
        for (int j=0;j<yLen-1;j++){
            count[colors[i][j]]+= (xcors[i+1]-xcors[i])*(ycors[j+1]-ycors[j]);
        }
    }
    for (int i=1;i<=2500;i++){
        if (count[i]>0){
            cout<<i<<" "<<count[i]<<endl;
            fout<<i<<" "<<count[i]<<endl;
        }
    }
    return 0;
}

