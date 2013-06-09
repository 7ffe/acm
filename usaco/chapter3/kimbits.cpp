/*
ID: silasli2
PROG: kimbits
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

long C[100][100];
int calcCombinatinon(){
    C[0][0]=1;
    C[1][0]=1;C[1][1]=1;
    for (int i=2;i<100;i++){
        C[i][0]=1;
        for (int j=1;j<i;j++){
            C[i][j] = C[i-1][j-1]+C[i-1][j];
        }
        C[i][i]=1;
    }
}

long K(long N, long L){
    long ans=0;
    for (int i=0;i<=L&&i<=N;i++){
        ans+=C[N][i];
    }
    return ans;
}

int main() {
    ofstream fout ("kimbits.out");
    ifstream fin ("kimbits.in");
    unsigned long N,L,I;
    fin>>N>>L>>I;
    calcCombinatinon();


    cout<<N<<' '<<L<<' '<< I<<endl;
    long total = K(N, L);
    string ans="";

    int NN=N;
    for (int n=1;n<=NN;n++){
        long takeZero = K(N-1, L);
        //cout<<I<<' '<<total<<' '<<takeZero<<endl;
        if (I>takeZero){
            ans+="1";
            N--;
            L--;
            total = total-takeZero;
            I = I-takeZero;
        }else{
            ans+="0";
            N--;
            total=takeZero;
        }
    }
    cout<<ans<<endl;
    fout<<ans<<endl;
/*
    unsigned long n= 2147483647 ;
    n++;
    cout<<n<<endl;*/
    return 0;
}
