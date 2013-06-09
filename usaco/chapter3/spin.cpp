/*
ID: silasli2
PROG: spin
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    ofstream fout ("spin.out");
    ifstream fin ("spin.in");
    int speed[5], num[5], start[5][5], extent[5][5];
    for (int i=0;i<5;i++){
        fin>>speed[i]>>num[i];
        for (int j=0;j<num[i];j++){
            fin>>start[i][j]>>extent[i][j];
        }
    }
    int light[360];
    int sec;
    int found=0;
    for (sec=0;sec<360 && !found;sec++){
        memset(light, 0, sizeof(int)*360);
        for (int i=0;i<5;i++){
            for (int j=0;j<num[i];j++){
                for (int k=start[i][j]+speed[i]*sec; k<=start[i][j]+speed[i]*sec+ extent[i][j];k++){
                    light[k%360]++;
                }
            }
        }
        int max=0;
        for (int i=0;i<360;i++){
            if (light[i]==5){
                cout<<sec<<endl;
                fout<<sec<<endl;
                found=1;
                break;
            }
            if (light[i]>max){
                max=light[i];
            }
        }
        //cout<<max<<endl;
    }
    if (sec==360){
        cout<<"none"<<endl;
        fout<<"none"<<endl;
    }

    return 0;
}
