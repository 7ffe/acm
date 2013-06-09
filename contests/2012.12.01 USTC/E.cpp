#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
int graph[101][101];
int big[101][101], dist[101];
int que[200], que_end, cur,inque[101];
int answer;
bool found;
int meizino;
int main(){
    freopen("E.txt", "r", stdin);
    int n, m;
    while (cin>>n>>m){
        answer = 1000000000;
        found=false;
        for (int i=0;i<=100;i++){
            for(int j=0;j<=100;j++){
                graph[i][j]=-1;
                big[i][j] = 0;
            }
            dist[i] =1000000000;
            inque[i] = 0;
        }

        for (int i=0;i<m;i++){
            int from, to ,v;
            cin>>from>>to>>v;
            graph[from][to] = v;
            graph[to][from] = v;
        }
        /*
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++)
                cout<<graph[i][j]<<' ';
            cout<<endl;
        }cout<<endl;
*/
        int meizi[4];
        cin>>meizi[0]>>meizi[1]>>meizi[2]>>meizi[3];
        /*int ans[4];
        ans[0] = 1000000000;
        ans[1] = 1000000000;
        ans[2] = 1000000000;
        ans[3] = 1000000000;
*/
        for (int ii = 1;ii<=n;ii++)
            for (int jj =1;jj<=n;jj++) if (graph[ii][jj]!=-1){
                int tmp = graph[ii][jj];

                graph[ii][jj]/=3;
                graph[jj][ii]/=3;
                //SPFA

                for (int i=1;i<=n;i++){
                    dist[i]=1000000000;
                    inque[i]=0;
                }

                cur=0;
                que_end=0;
                que[0]= 1;
                dist[1]=0;
                inque[1] =1;
                while (que_end>=cur){
                    //loosen on que[cur]
                    for (int i=1;i<=n;i++){
                        if (graph[que[cur]][i]!=-1 && dist[i]>dist[que[cur]]+graph[que[cur]][i]){
                            dist[i]=dist[que[cur]]+graph[que[cur]][i];


                            if (inque[i]==0){
                                que[++que_end] = i;
                                inque[i]=1;
                            }
                        }
                    }
                    inque[que[cur]] = 0;
                    cur++;
                }

        /*
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
*/
                if (dist[meizi[0]]==dist[meizi[1]] || dist[meizi[0]]==dist[meizi[2]] || dist[meizi[0]]==dist[meizi[3]] ||
                    dist[meizi[1]]==dist[meizi[2]] || dist[meizi[1]]==dist[meizi[3]] || dist[meizi[2]]==dist[meizi[3]]){
                        continue;
                    }
                int sol=1000000000;
                for (int i=0;i<4;i++){
                    if (dist[meizi[i]]<sol){
                        sol = dist[meizi[i]];
                    }
                }
                int count=0;
                for (int i=0;i<4;i++){
                    if (dist[meizi[i]]==sol){
                        count++;
                    }
                }
                if (count==1&& sol<answer){
                    answer=sol;
                    found=true;
                    for (int i=0;i<4;i++){
                        if (dist[meizi[i]]==sol){
                        meizino=i;
                        }
                    }
                }
                graph[ii][jj]= tmp;
                graph[jj][ii]= tmp;
            }
            if (!(dist[meizi[0]]==dist[meizi[1]] || dist[meizi[0]]==dist[meizi[2]] || dist[meizi[0]]==dist[meizi[3]] ||
                    dist[meizi[1]]==dist[meizi[2]] || dist[meizi[1]]==dist[meizi[3]] || dist[meizi[2]]==dist[meizi[3]])){
            int count=0;
            for (int i=0;i<4;i++){
                if (meizi[i]==1){
                    count++;
                }
            }
            if (count==1){
                found=true;
                for (int i=0;i<4;i++)
                    if (meizi[i]==1){
                    meizino=i;
                    //cout<<"hi "<<i;
                    }
            }
                    }
            if (found==true){
                //cout<<answer<<" hi "<<endl;
            if (meizino==0){
                cout<<"Hehe"<<endl;
            }else if (meizino==1){
                cout<<"Quxizao"<<endl;
            }else if (meizino==2){
                cout<<"Qushuijiao"<<endl;
            }else if (meizino==3){
                cout<<"Quchidongxi"<<endl;
            }
            }else{
                cout<<"Shuiwujiaoqu"<<endl;
            }



    }

}
