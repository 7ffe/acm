/*
ID: silasli2
PROG: butter
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


using namespace std;
ofstream fout ("butter.out");
ifstream fin ("butter.in");

int N,P,C;
int edges[810][1450];
int edges_len[810][1450];
int edge_num[810];
int cowcount[810];
int inque[810];

int que[810*2];
int dist[810];
int ans;

int minPath = 225*1450*500;
int calc(){

    for (int p=1;p<=P;p++){
        //place sugar in p
        memset(que, 0, sizeof(int)*810*2);
        memset(inque, 0, sizeof(int)*810);

        int cur=0;
        int que_end=0;
        for (int i=1;i<=P;i++){
            dist[i]=225*1450;
        }
        que[0]=p;
        dist[p]=0;
        inque[p]=1;
        while (que_end>=cur){
            //loosen on que[cur]
            for (int i=0;i<edge_num[que[cur]];i++){
                if (dist[edges[que[cur]][i]] > dist[que[cur]]+edges_len[que[cur]][i]){
                    dist[edges[que[cur]][i]] = dist[que[cur]]+edges_len[que[cur]][i];
                    if (inque[edges[que[cur]][i]]==0){
                        que[++que_end] = edges[que[cur]][i];
                        inque[edges[que[cur]][i]] = 1;
                    }
                }

            }
            inque[que[cur]] = false;
            cur++;
        }

        int total =0;
        for (int i=1;i<=P;i++){
            total += cowcount[i] * dist[i];
        }
        if (total<minPath){
            minPath=total;
            ans = p;
        }
    }
}
int output(){
    cout<<minPath<<endl;
    fout<<minPath<<endl;
}
int init(){

    //input
    fin>>N>>P>>C;
    for (int i=0;i<N;i++){
        int tmp;
        fin>>tmp;
        cowcount[tmp]++;
    }
    for (int i=0;i<C;i++){
        int a,b,c;
        fin>>a>>b>>c;
        edges[a][edge_num[a]] = b;
        edges[b][edge_num[b]] = a;
        edges_len[a][edge_num[a]] = c;
        edges_len[b][edge_num[b]] = c;
        edge_num[a]++;
        edge_num[b]++;

    }

    return 0;
}

int main() {
    memset(edges, 0, 810*1450*sizeof(int));
    memset(edges_len, 0, 810*1450*sizeof(int));
    memset(edge_num, 0, 810*sizeof(int));
    memset(cowcount, 0, 810*sizeof(int));
    memset(inque, 0, 810*sizeof(int));

    init();
    calc();
    output();



    return 0;
}
