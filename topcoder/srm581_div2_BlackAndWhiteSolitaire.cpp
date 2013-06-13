#include <string>
using namespace std;
class BlackAndWhiteSolitaire{
	public: 
		int minimumTurns(string cardFront){
			//B, W
			int cnt1=0, cnt2=0;
			char color[2] = {'B', 'W'};
			for (int i=0;i<cardFront.size();i++){
				if (cardFront[i]!=color[i%2])
					cnt1++;
				if (cardFront[i]!=color[(i+1)%2])
					cnt2++;
			}
			if (cnt1<cnt2) return cnt1;
			else return cnt2;
		}
};