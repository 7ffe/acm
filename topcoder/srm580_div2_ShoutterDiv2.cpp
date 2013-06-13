#include <vector> 
using namespace std; 
class ShoutterDiv2{ 
  public: 
    int count(vector <int> s, vector <int> t){ 
      int ans=0; 
      int n,i,j; 
      n = s.size(); 
      for (i=0;i<n;i++) 
        for (j=i+1;j<n;j++){ 
          if ((s[i]<=s[j] && s[j]<=t[i]) || (s[i]<=t[j] && t[j]<=t[i])) 
            ans++; 
          else if ((s[j]<=s[i] && s[i]<=t[j]) || (s[j]<=t[i] && t[i]<=t[j])) 
            ans++; 
        } 
      return ans; 
    } 
};