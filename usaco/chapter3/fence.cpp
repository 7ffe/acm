/*
ID: silasli2
PROG: fence
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


using namespace std;
ofstream fout ("fence.out");
ifstream fin ("fence.in");
const int N=500;
int edgeNum[N+1];
int matrix[N+1][N+1];
int path[2*N+20];
int pos;

int init(){
    int m;
    fin>>m;
    for (int i=0;i<m;i++){
        int a,b;
        fin>>a>>b;
        edgeNum[a]++;
        edgeNum[b]++;
        matrix[a][b]++;
        matrix[b][a]++;
    }
    return 0;
}

inline int findCircuit(int i){
    if (edgeNum[i]==0){
        path[pos++] = i;
    }else{
        while (edgeNum[i]>0){
            for (int j=1;j<=N && edgeNum[i]>0;j++) if (matrix[i][j]>0){
                edgeNum[i]--;edgeNum[j]--;
                matrix[i][j]--;
                matrix[j][i]--;
                findCircuit(j);
            }
        }
        path[pos++] = i;
    }
}

inline int solve(){
    int start;
    for (start=1;start<=N;start++){
        if (edgeNum[start]%2==1){
            break;
        }
    }
    if (start==N+1){
        start=1;
    }
    cout<<start<<endl;
    findCircuit(start);
    return 0;
}
int output(){
    while (pos>0){
        pos--;
        cout<<path[pos]<<endl;
        fout<<path[pos]<<endl;
    }
    return 0;
}

int main() {
    memset(edgeNum, 0, sizeof(int)*(N+1));
    memset(matrix, 0, sizeof(int)*(N+1)*(N+1));
    pos=0;
    memset(path, 0, sizeof(int)*(2*N+20));

    init();
    solve();
    output();
    return 0;
}
