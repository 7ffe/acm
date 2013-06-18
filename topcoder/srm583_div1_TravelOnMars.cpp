#include<vector> 
#include<map> 
#include<algorithm> 
#include<string>
#include<sstream>
using namespace std; 
class 
TravelOnMars{ 
  public: 
  	int min(int a, int b){
  		if (a<b) return a;
  		else return b;
  	}
  	int minTimes(vector <int> range, int start, int end){
  		int N = range.size();
  		int steps[N];
  		for (int i=0;i<N;i++)
  			steps[i] = N*2;
  		steps[start] = 0;
  		/*
  		for (int d = 1;d<N/2;d++){
  			
  		}*/
		for (int i=0;i<N;i++)
			for (int k=0;k<N;k++){
			for (int s = 0;s<N;s++){
				for (int d = 1; d<=range[s];d++){
					steps[(s+d+N)%N] = min(steps[(s+d+N)%N], steps[s] +1);
					steps[(s-d+N)%N] = min(steps[(s-d+N)%N], steps[s] +1);
				}

			}
			}
		return steps[end];
  	}
};