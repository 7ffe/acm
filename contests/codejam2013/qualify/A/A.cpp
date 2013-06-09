#include <stdio.h>
#include <iostream>
using namespace std;
int nodot(char d[4][5]){
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            if (d[i][j]=='.')
                return false;
    return true;
}
int check(char d[4][5]){
    //0: X won
    //1: O won
    //2: draw
    //3: no done yet
    for (int i=0;i<4;i++){
        if ((d[i][0]=='X'||d[i][0]=='T')&&(d[i][1]=='X'||d[i][1]=='T')&&(d[i][2]=='X'||d[i][2]=='T')&&(d[i][3]=='X'||d[i][3]=='T'))
            return 0;
        else if ((d[i][0]=='O'||d[i][0]=='T')&&(d[i][1]=='O'||d[i][1]=='T')&&(d[i][2]=='O'||d[i][2]=='T')&&(d[i][3]=='O'||d[i][3]=='T'))
            return 1;
        else if ((d[0][i]=='X'||d[0][i]=='T')&&(d[1][i]=='X'||d[1][i]=='T')&&(d[2][i]=='X'||d[2][i]=='T')&&(d[3][i]=='X'||d[3][i]=='T'))
            return 0;
        else if ((d[0][i]=='O'||d[0][i]=='T')&&(d[1][i]=='O'||d[1][i]=='T')&&(d[2][i]=='O'||d[2][i]=='T')&&(d[3][i]=='O'||d[3][i]=='T'))
            return 1;
        else if ((d[0][0]=='X'||d[0][0]=='T')&&(d[1][1]=='X'||d[1][1]=='T')&&(d[2][2]=='X'||d[2][2]=='T')&&(d[3][3]=='X'||d[3][3]=='T'))
            return 0;
        else if ((d[0][0]=='O'||d[0][0]=='T')&&(d[1][1]=='O'||d[1][1]=='T')&&(d[2][2]=='O'||d[2][2]=='T')&&(d[3][3]=='O'||d[3][3]=='T'))
            return 1;
        else if ((d[0][3]=='X'||d[0][3]=='T')&&(d[1][2]=='X'||d[1][2]=='T')&&(d[2][1]=='X'||d[2][1]=='T')&&(d[3][0]=='X'||d[3][0]=='T'))
            return 0;
        else if ((d[0][3]=='O'||d[0][3]=='T')&&(d[1][2]=='O'||d[1][2]=='T')&&(d[2][1]=='O'||d[2][1]=='T')&&(d[3][0]=='O'||d[3][0]=='T'))
            return 1;
    }
    if (nodot(d))
        return 2;
    else return 3;
}
int main(){

    //freopen("A-small-attempt1.in", "r", stdin);
    //freopen("A-small-attempt1.out", "w", stdout);
    //freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w", stdout);


    //freopen("A.in", "r", stdin);
    //freopen("A.out", "w", stdout);

    int T,t;
    cin>>T;
    char data[4][5];
    for (t = 1; t<=T; t++){
        for (int i=0;i<4;i++)
            cin>>data[i];

        cout<<"Case #"<<t<<": ";
        switch (check(data)){
            case 0: cout<<"X won";
                break;
            case 1: cout<<"O won";
                break;
            case 2: cout<<"Draw";
                break;
            case 3: cout<<"Game has not completed";
                break;
        }
        cout<<endl;
    }
    return 0;
}
