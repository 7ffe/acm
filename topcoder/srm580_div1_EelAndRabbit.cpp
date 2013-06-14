#include<vector> 
#include<map> 
#include<algorithm> 
#include<string>
#include<sstream>
using namespace std; 
class EelAndRabbit{ 
  public: 
  	int getmax(vector <int> l, vector <int> t){
  		int ans = 0;
  		int n = l.size();
  		for (int i=0;i<n;i++)
  			for (int j=0;j<n;j++){
  				int a = t[i], b = t[j];
  				int tmp = 0;
  				for (int k=0;k<n;k++)
  					if ((a>=t[k] && a<=t[k]+l[k]) || (b>=t[k] && b<=t[k]+l[k]))
  						tmp++;
  				if (tmp>ans) ans = tmp;
  			}
  		return ans;
  	}
};
