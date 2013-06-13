#include <string>
#include <vector>
#include <map>
using namespace std;
class SurveillanceSystem{
	public:
		bool deletable(string s, int k, map<int, int> &stat, vector<int> &see, int L){
			map<int, int> cnt;
			for (int i=0;i<see.size();i++)
				cnt[see[i]] = 0;
			for (int i=0;i+L-1<k;i++){
				int tmp=0;
				for (int j=0;j<L;j++)
					if (s[i+j]=='X') tmp++;
				if (cnt.count(tmp)==1)
					cnt[tmp] +=1;
			}
			for (int i=k+1;i+L-1<s.size();i++){
				int tmp = 0;
				for (int j=0;j<L;j++)
					if (s[i+j]=='X') tmp++;
				if (cnt.count(tmp)==1)
					cnt[tmp] +=1;
			}
			for (int i=0;i<see.size();i++){
				if (cnt[see[i]]< stat[see[i]])
					return false;
			}
			return true;
		}
		string getContainerInfo(string s, vector <int> see, int L){
			map<int, int> stat;
			for (int i=0;i<see.size();i++)
				stat[see[i]] = 0;
			for (int i=0;i<see.size();i++)
				stat[see[i]] += 1;
			bool possible[s.size()];
			for (int i=0;i<s.size();i++)
				possible[i] = false;
			for (int i=0;i+L-1<s.size();i++){
				int tmp = 0;
				for (int j=0;j<L;j++)
					if (s[i+j]=='X') tmp++;
				if (stat.count(tmp)==1)
					for (int j=0;j<L;j++)
						possible[i+j] = true;
			}
			string ans = "";
			for (int i=0;i<s.size();i++)
				//(string s, int k, map<int, int> &stat, vector<int> &see, int L){
				if (!deletable(s, i, stat, see, L))
					ans += "+";
				else if (possible[i])
					ans += "?";
				else ans += "-";
			return ans;
		}
};