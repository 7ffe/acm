/*
ID: silasli2
PROG: ratios
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int test(){
    cout<<-12/-4;
}

int main() {
    ofstream fout ("ratios.out");
    ifstream fin ("ratios.in");
    int a,a1,a2,a3,b,b1,b2,b3,c,c1,c2,c3,a12,b12,c12, a4,b4,c4, k4=10000;
    fin>>a>>b>>c;

    fin>>a1>>b1>>c1;
    fin>>a2>>b2>>c2;
    fin>>a3>>b3>>c3;

    for (int k1=0;k1<100;k1++){
        for (int k2= 0;k2<100;k2++){
            a12 = k1*a1+k2*a2;
            b12 = k1*b1+k2*b2;
            c12 = k1*c1+k2*c2;
            int k3 = ( (a12+b12+c12)*a - a12*(a+b+c) )/( a3*(a+b+c) - a*(a3+b3+c3));

            //check
            if ((a12+k3*a3)*b==(b12+k3*b3)*a && (b12+k3*b3)*c==(c12+k3*c3)*b ){
                if ((a12+k3*a3)/a<k4 && (a12+k3*a3)/a>0){
                    k4 = (a12+k3*a3)/a;
                    a4=k1;b4=k2;c4=k3;
                }
            }
        }
    }
    if (k4==10000){
        cout<<"NONE"<<endl;
        fout<<"NONE"<<endl;
    }else{
        cout<<a4<<' '<<b4<<' '<<c4<<' '<<k4<<endl;
        fout<<a4<<' '<<b4<<' '<<c4<<' '<<k4<<endl;
    }

    return 0;
}
