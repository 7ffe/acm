#include<vector> 
#include<map> 
#include<algorithm> 
using namespace std; 
class EelAndRabbit{ 
  public: 
    int getmax(vector <int> l, vector <int> t){ 
      int ans = 0, from, end; 
      map<int, vector<int> > cnt; 
      vector<int> keys; 
      for (int i=0;i<l.size();i++){ 
        from = t[i]; 
        end = t[i] + l[i]; 
        if (cnt.count(from)==0){ 
          cnt[from] = vector<int>(); 
          keys.push_back(from); 
        } 
        if (cnt.count(end)==0){ 
          cnt[end] = vector<int>(); 
          keys.push_back(end); 
        } 
      } 
      for (int i=0;i<keys.size();i++){ 
         int point = keys[i]; 
         for (int j=0;j<l.size();j++){ 
           from = t[j]; 
           end = t[j] + l[j]; 
           if (from<=point && point<=end) 
             cnt[point].push_back(j); 
         } 
      } 
      for (int i=0;i<keys.size();i++) 
        for (int j=0;j<keys.size();j++){ 
          vector<int> tmp; 
          for (int k=0;k<cnt[keys[i]].size();k++) 
            tmp.push_back(cnt[keys[i]][k]); 
          for (int k=0;k<cnt[keys[j]].size();k++) 
            tmp.push_back(cnt[keys[j]][k]); 
          int new_ans = 0; 
          sort(tmp.begin(),tmp.end()); 
          if (tmp.size()>0) new_ans++; 
          for (int k=1;k<tmp.size();k++) 
            if (tmp[k]!=tmp[k-1]) 
              new_ans++; 
          ans = max(new_ans, ans); 
        } 
       
      return ans; 
    } 
};