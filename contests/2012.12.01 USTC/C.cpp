#include <iostream>
#include <list>

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cstdlib>

#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int visited[10001];
//int que[10001], pos, que_end;
int min_ans;
int ans_local;
int main(){
    int n;
    freopen("C.txt", "r", stdin);
    while (scanf("%d",&n)!=EOF){
        if (n==0) break;
        list<int> edges[10001];
        list<int> reedges[10001];
        for (int i=1;i<n;i++){
            int from , to;
            //cin>>from>>to;
            scanf("%d%d",&from,&to);
            edges[from].push_back(to);
            reedges[to].push_back(from);

        }
        min_ans = 10001;
        for (int start =1;start<=n;start++){
            memset(visited, 0,sizeof(int)* (n+1));
            //pos=0;
            //que_end=0;
            //que[0]=start;
            queue<int> que;
            que.push(start);
            visited[start]=1;
            ans_local = 0;
            bool run=false;
            while (!que.empty()){
                				list<int>::iterator it;
				int cur = que.front();
				que.pop();
				for (it=edges[cur].begin();it!=edges[cur].end();it++){
				    int next = *it;
				    if (! visited[next]){
				        //que[++que_end] = next;
				        que.push(next);
				        visited[next]=1;
				    }
				}
                for (it=reedges[cur].begin();it!=reedges[cur].end();it++){
				    int next = *it;
				    if (! visited[next]){
				        //que[++que_end] = next;
				        que.push(next);
				        visited[next]=1;
				        ans_local++;
				        if (ans_local>=min_ans){
				            run=true;
				            break;
				        }
				        //cout<<ans_local<<' ';
				    }
                }
                //pos++;
                if (run){break;}

            }
            if (ans_local<min_ans){
                min_ans = ans_local;
            }
        }
        cout<<min_ans<<endl;
        //cout<<endl;


    }


}
