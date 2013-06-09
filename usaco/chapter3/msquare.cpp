/*
ID: silasli2
PROG: msquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream fout ("msquare.out");
ifstream fin ("msquare.in");


int fac[9];
struct item{
    item(){}

    item(char _s[], char _type, int _prev, int _step){
        for (int i=0;i<8;i++)
            s[i] = _s[i];
        type = _type;
        prev = _prev;
        step = _step;
    }

    char s[8];
    char type;
    int prev;
    int step;

}que[40320+20];
bool reached[40320+20];
int cantor(char *s){
    int ans=0;
    for (int i=1;i<8;i++){
        for (int j=0;j<i;j++){
            if (s[i]>s[j]){
                ans+= fac[i];
            }
        }
    }
    return ans;
}
item transform(int prev, char type){
    char s2[8];
    char* s = que[prev].s;
    if (type =='A'){
        s2[0]=s[7]; s2[1]=s[6]; s2[2]=s[5]; s2[3]=s[4];
        s2[7]=s[0]; s2[6]=s[1]; s2[5]=s[2]; s2[4]=s[3];
    }else if (type == 'B'){
        s2[0]=s[3]; s2[1]=s[0]; s2[2]=s[1]; s2[3]=s[2];
        s2[7]=s[4]; s2[6]=s[7]; s2[5]=s[6]; s2[4]=s[5];
    }else if (type == 'C'){
        s2[0]=s[0]; s2[1]=s[6]; s2[2]=s[1]; s2[3]=s[3];
        s2[7]=s[7]; s2[6]=s[5]; s2[5]=s[2]; s2[4]=s[4];
    }else{
        cout<<"ERROR, not A or B or C"<<endl;
    }
    return item(s2, type, prev, que[prev].step+1);
}

int calcFac(){
    fac[0]=1;
    for (int i=1;i<9;i++)
        fac[i] = fac[i-1]*i;
}

int que_end, cur;
char sd[8];

int init(){
    calcFac();
    que_end=0;
    cur=0;
    que[cur] = item("12345678", 'Z', -1, 0);
    for (int i=0;i<40320+20;i++)
        reached[i] = false;
    int d;
    for (int i=0;i<8;i++){
        fin>>d;
        sd[i] = '0'+d;
    }
}
bool check(int id){
    char * s = que[id].s;
    for (int i=0;i<8;i++)
        if (s[i]!=sd[i])
            return false;
    return true;
}
int search(){
    if (check(0)){
        return 0;//initial == target
    }
    while(true){
        for (char type = 'A';type<='C';type++){
            item tmp = transform(cur, type);
            int id = cantor(tmp.s);
            if (!reached[id]){
                que[++que_end] = tmp;
                if (check(que_end)){
                    return 0;
                }
                reached[id]=true;
            }
        }
        cur++;
    }

}
int output(){
    cout<<que[que_end].step<<endl;
    fout<<que[que_end].step<<endl;
    string action="";
    while (que[que_end].prev!=-1){
        action = que[que_end].type + action;
        que_end = que[que_end].prev;
    }
    cout<<action<<endl;
    fout<<action<<endl;
}
int main() {

    init();
    search();
    output();
    return 0;
}
