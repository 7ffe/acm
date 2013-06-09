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
short int dist[H_Max*W_Max][4];
short int path[H_Max*W_Max][4];
ofstream fout ("maze1.out");
ifstream fin ("maze1.in");
int W, H;

int printGrid(int data[][HW_Max], int h, int w){
    for (int i = 0;i<h;i++){
        for (int j = 0;j<w;j++){
            fout<<data[i][j]<<' ';
        }
        fout<<endl;
    }
}
int NeighborId(int id, int para){
    int i = id/W;
    int j = id%W;
    if (para==0){
        i--;
    }else if (para ==1){
        i++;
    }else if (para ==2){
        j--;
    }else if (para == 3){
        j++;
    }
    return i*W+j;
}
int main() {



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
        for (int j = 0; j<4; j++){
            dist[i][j] = distMax;//initialize to very large
            path[i][j] = distMax;
        }

    }

    //Build the dist table
    for (int i = 0; i<H;i++){
        for (int j = 0; j<W;j++){
            //to its right

            int i2 = i;
            int j2 = j+1;
            if (j2<W){
                if (oldMap[2*i+1][2*j+1+1]==' '){//connect to the right block
                    dist[i*W+j][3] = 1;
                    dist[i2*W+j2][2] = 1;
                }
            }
            //to its bottom
            i2 = i+1;
            j2 = j;
            if (i2<H){
                if (oldMap[2*i+1+1][2*j+1]==' '){
                    dist[i*W+j][1]=1;
                    dist[i2*W+j2][0]=1;
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

    //Dijstra Exit1
    //init
    int minpath[HW_Max];
    int visited[HW_Max];
    const int N = HW_Max;
    int z = H*W;
    for (int i = 0;i<HW_Max;i++){
        minpath[i] = distMax;
        visited[i] = 0;
    }
    minpath[eid1] = 0;
    while (z--){
        //find min
        int cur_min=distMax+1;
        int id_min;
        for (int i = 0;i<N; i++){
            if ((visited[i]==0)&&(minpath[i]<cur_min)){
                cur_min = minpath[i];
                id_min = i;
            }
        }
        //mark it
        visited[id_min] = 1;
        //update its neighbour
        int id_nei;
        //0 up
        for (int i = 0;i<4;i++){
            id_nei = NeighborId(id_min, i);
            minpath[id_nei] = min2(minpath[id_nei], cur_min+dist[id_min][i]);
        }
    }
    /*
    for (int i = 0;i<H*W;i++){
        cout<<minpath[i]<<endl;
    }*/
    //make a backup

    int minpath2[N];
    for (int i =0;i<H*W;i++){
        minpath2[i] = minpath[i];
    }
    for (int i = 0;i<HW_Max;i++){
        minpath[i] = distMax;
        visited[i] = 0;
    }
    //for exit 2
    minpath[eid2] = 0;
    z=H*W;
    while (z--){
        //find min
        int cur_min=distMax+1;
        int id_min;
        for (int i = 0;i<N; i++){
            if ((visited[i]==0)&&(minpath[i]<cur_min)){
                cur_min = minpath[i];
                id_min = i;
            }
        }
        //mark it
        visited[id_min] = 1;
        //update its neighbour
        int id_nei;
        //0 up
        for (int i = 0;i<4;i++){
            id_nei = NeighborId(id_min, i);
            minpath[id_nei] = min2(minpath[id_nei], cur_min+dist[id_min][i]);
        }
    }
    int res = 0;
    for (int i = 0;i<H*W;i++){
        //cout<<minpath[i]<<" "<<minpath2[i]<<endl;
        res = max2(res, min2(minpath[i], minpath2[i]));
    }
    res++;
    cout<<res<<endl;
    fout<<res<<endl;
    return 0;

}
