#include <vector>
#include <string>
using namespace std;
class TreeUnionDiv2{
	public:
		void permute(int m, int N, int K){
			if (m==N){
				int tmp = 0;
				for (int i=0; i<N;i++)
					for (int j=i+1;j<N;j++)
						if (dist1[i][j] + dist2[p[i]][p[j]] +2 == K)
							tmp++;
				if (tmp>ans) ans = tmp;
				return;
			}
			for (int i=0;i<N;i++)
				if (!used[i]){
					p[m] = i;
					used[i] = 1;
					permute(m+1, N, K);
					used[i] = 0;
				}
		}
		int maximumCycles(vector <string> tree1, vector <string> tree2, int K){
			int N = tree1.size();
			int INF = 1000000000;
			for (int i=0;i<N;i++)
				for (int j=0;j<N;j++){
					dist1[i][j] = INF;
					dist2[i][j] = INF;
				}
			for (int i=0;i<N;i++){
				dist1[i][i] = 0;
				dist2[i][i] = 0;
				for (int j=0;j<N;j++){
					if (tree1[i][j] == 'X') dist1[i][j] = 1;
					if (tree2[i][j] == 'X') dist2[i][j] = 1;
				}
			}
			for (int k=0;k<N;k++)
				for (int i=0;i<N;i++)
					for (int j=0;j<N;j++){
						if (dist1[i][j]> dist1[i][k] + dist1[k][j])
							dist1[i][j] =  dist1[i][k] + dist1[k][j];
						if (dist2[i][j]> dist2[i][k] + dist2[k][j])
							dist2[i][j] =  dist2[i][k] + dist2[k][j];
					}
			
			ans = 0;
			for (int i=0;i<N;i++)
				used[i]=0;
			permute(0, N, K);
			return ans;
		}
		int ans;
		int dist1[10][10];
		int dist2[10][10];
		int p[10];
		int used[10];
			
};