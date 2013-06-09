/*
ID: silasli2
PROG: agrinet
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("agrinet.out");
    ifstream fin ("agrinet.in");
    const int NM = 100;
    const int Dist_Max = 100000*NM;
    int N;
    fin>>N;
    int dist[NM][NM];
    for (int i = 0;i<N;i++){
        for (int j = 0;j<N;j++){
            fin>>dist[i][j];
        }
    }

    //test input
    /*
    fout<<N<<endl;
    for (int i = 0;i<N;i++){
        for (int j = 0;j<N;j++){
            fout<<dist[i][j];
        }
        fout<<endl;
    }*/
    //Prim Minimum Spanning Tree
    int intree[NM];
    int source[NM];
    int distance[NM];
    int total=0;
    //init
    for (int i = 0;i<N;i++){
        intree[i]=0;
        source[i]=-1;
        distance[i] = Dist_Max;
    }
    //push node 1
    source[0]=-1;
    distance[0]=0;
    //push the other n-1 nodes one by one
    for (int k = 0; k<N;k++){
        //find closest node to the so-far tree
        int id_min;
        int dist_min=Dist_Max;

        for (int i = 0;i<N;i++){
            if (intree[i]==0 && distance[i]<dist_min){
                id_min=i;
                dist_min = distance[i];
            }
        }
        //push this node into tree
        intree[id_min] = 1;
        total += dist_min;
        //update
        for (int i = 0;i<N;i++){
            if (intree[i]==0 && dist[i][id_min]<distance[i]){
                distance[i] = dist[i][id_min];
                source[i] = id_min;
            }
        }

    }
    fout<<total<<endl;
    return 0;
}
