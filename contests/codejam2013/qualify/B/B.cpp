#include <stdio.h>
#include <iostream>
using namespace std;

int min2(int a, int b){
    if (a<b) return a;
    else return b;
}
int check(int data[100][100],
    int row[100],
    int col[100], int N, int M){
        for (int i=0;i<N; i++)
            for (int j=0;j<M;j++)
                if (data[i][j]!=min(row[i], col[j]))
                    return false;
        return true;
}

int main(){

    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B-small-attempt0.out", "w", stdout);
    //freopen("B-large.in", "r", stdin);
    //freopen("B-large.out", "w", stdout);


    //freopen("B.in", "r", stdin);
    //freopen("B.out", "w", stdout);

    int T,t, M, N;
    cin>>T;
    int data[100][100];
    int row[100];
    int col[100];
    for (t = 1; t<=T; t++){
        cin>>N>>M;
        //input
        for (int i=0;i<N;i++)
            for (int j=0;j<M;j++)
                cin>>data[i][j];

        //calc row
        int tmin;
        for (int i=0;i<N;i++){
            tmin = 0;
            for (int j=0;j<M;j++){
                if (data[i][j]>tmin)
                    tmin = data[i][j];
            }
            row[i] = tmin;
        }
        for (int j=0;j<M;j++){
            tmin = 0;
            for (int i=0;i<N;i++){
                if (data[i][j]>tmin)
                    tmin = data[i][j];
            }
            col[j] = tmin;
        }
        /*int check(int data[100][100],
    int row[100],
    int col[100], int N, int M){*/
        if (check(data, row, col, N, M))
            cout<<"Case #"<<t<<": YES"<<endl;
        else cout<<"Case #"<<t<<": NO"<<endl;
    }
    return 0;
}
