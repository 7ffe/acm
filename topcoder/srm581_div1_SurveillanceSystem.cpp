#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
class TreeUnion{
	public:
		double expectedCycles(vector <string> tree1, vector <string> tree2, int K){
			string data1 = "", data2= "";
			for (int i=0;i<tree1.size();i++)
				data1+= tree1[i];
			for (int i=0;i<tree2.size();i++)
				data2+= tree2[i];
			vector<int> pointto1, pointto2;
			stringstream ss1(data1), ss2(data2);
			int tmp;
			int cnt = 1;
			while (ss1>>tmp){
				pointto1.push_back(tmp);
				cnt++;
			}
			cnt = 1;
			while (ss2>>tmp){
				pointto2.push_back(tmp);
				cnt++;
			}
			int N = cnt;
			int dist1[N][N], dist2[N][N];
			for (int i=0;i<N;i++)
				for (int j=0;j<N;j++){
					dist1[i][j] = 1000000000;
					dist2[i][j] = 1000000000;
				}
			for (int i=0;i<N-1;i++){
				dist1[pointto1[i]][i+1] = 1;
				dist2[pointto2[i]][i+1] = 1;
				dist1[i+1][pointto1[i]] = 1;
				dist2[i+1][pointto2[i]] = 1;
				dist1[i][i] = 0;
				dist2[i][i] = 0;
			}
			for (int k = 0;k<N;k++)
				for (int i=0;i<N;i++)
					for (int j = 0; j<N;j++){
						if (dist1[i][j]>dist1[i][k]+dist1[k][j])
							dist1[i][j] = dist1[i][k]+dist1[k][j];
						if (dist2[i][j]>dist2[i][k]+dist2[k][j])
							dist2[i][j] = dist2[i][k]+dist2[k][j];
					}
			map<int, int> len2cnt1, len2cnt2;
			for (int i=0;i<=N;i++){
				len2cnt1[i] = 0;
				len2cnt2[i] = 0;
			}
			for (int i=0;i<N;i++)
				for (int j=i+1;j<N;j++){
					len2cnt1[dist1[i][j]] = len2cnt1[dist1[i][j]] + 1;
					len2cnt2[dist2[i][j]] = len2cnt2[dist2[i][j]] + 1;
				}

			//calculate
			double sum  = 0.0;
			for (int i=1;i<=K-3;i++){
				sum += len2cnt1[i]*len2cnt2[K-2-i];
//				if (i!=K-2-i)
//					sum += len2cnt2[i]*len2cnt1[K-2-i];
			}
			return sum*2/N/(N-1);
			//return dist1[2][3];
		}
};
