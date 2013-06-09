#include <iostream>
using namespace std;
int main(){
    int z;
    cin>>z;
    const int N = 50;
    string name, _name;
    int num, _num;
    int time, _time;

    while (z--){
        int n;
        cin>>n;
        cin>>name>>num>>time;
        for (int i=1;i<n;i++){
            cin>>_name>>_num>>_time;
            if (_num>num || (_num==num && _time<time) || (_num==num && _time==time && _name<name)){
                name=_name;
                num=_num;
                time=_time;
            }
        }
        cout<<name<<endl;

    }

}
