#include <vector>
#include <string>
using namespace std;
class WallGameDiv2{
	public:
		int play(vector <string> costs){
			int n = costs.size();
			int m = costs[0].size();
			int dp[n][m];
			int c[n][m];
			for (int i=0;i<n;i++)
				for (int j=0;j<m;j++)
					if (costs[i][j]=='x') c[i][j] = -1;
					else c[i][j] = costs[i][j] - '0';
			dp[0][0] = 0;
			for (int i=1;i<m;i++){
				if (costs[0][i]=='x'){
					dp[0][i] = -1;
				}else{
					if (dp[0][i-1]==-1) dp[0][i] = -1;
					else dp[0][i] = dp[0][i-1] + c[0][i];
				}
			}
			for (int i = 1; i<n-1; i++){
				for (int j=0; j<m; j++) dp[i][j] = -1;
				for (int j=0; j<m; j++){
					int tmp = -1, tmp2;
					if (dp[i-1][j]>=0 && c[i][j]>=0)
						tmp = dp[i-1][j] + c[i][j];
					if (tmp<0) continue;
					tmp2 = tmp;
					dp[i][j] = max(dp[i][j], tmp);
					for (int k=j-1; k>=0 && c[i][k]>=0; k--){
						tmp += c[i][k];
						dp[i][k] = max(dp[i][k], tmp);
					}
					tmp = tmp2;
					for (int k=j+1; k<m  && c[i][k]>=0; k++){
						tmp += c[i][k];
						dp[i][k] = max(dp[i][k], tmp);
					}
				}
			}
			
			for (int j=0;j<m;j++){
				if (c[n-1][j]>=0 && dp[n-2][j]>=0)
					dp[n-1][j] = dp[n-2][j] + c[n-1][j];
				else
					dp[n-1][j] = -1;
			}
			int ans = 0;
			for (int j=0;j<m;j++)
				ans = max(ans, dp[n-1][j]);
			return ans;
		}	
};