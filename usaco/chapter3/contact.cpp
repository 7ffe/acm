/*
ID: silasli2
PROG: contact
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int power(int a, int b){
    //a**b
    int ans =1;
    for (int i=0;i<b;i++){
        ans*=a;
    }
    return ans;
}

string id2str(int id){
    string ans="";
    while (id>0){
        if (id%2==1){
            ans = "0"+ans;
            id = (id-1)/2;
        }else{
            ans = "1"+ans;
            id = (id-2)/2;
        }
    }
    return ans;
}
int swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
    return 0;
}
int quicksort(int data[], int head, int tail){
    if (head>=tail){
        return 0;
    }
    int p = (head+tail)/2;
    int midv = data[p];
    swap(data[p], data[tail]);
    int store = head;
    for (int i = head; i<=tail-1;i++){
        if (data[i]>midv){
            swap(data[i], data[store]);
            store++;
        }
    }
    swap(data[store], data[tail]);

    quicksort(data, head, store-1);
    quicksort(data, store+1, tail);
    return 0;
}

int main() {
    ofstream fout ("contact.out");
    ifstream fin ("contact.in");
    int A,B,N;
    fin>>A>>B>>N;
    string str, tmp;
    fin>>str;
    while((fin>>tmp)){
        str+=tmp;
    }
    //cout<<str<<endl;
    //cout<<str.length()<<endl<<endl;

    int strLen = str.length();

    const int BM = 12;
    const int TreeLen = 8192;
    int tree[TreeLen];
    memset(tree, 0, sizeof(int)*TreeLen);
    for (int head = 0;head<=strLen-A;head++){
        int p=0;
        for (int id = head;id<head+B && id<strLen;id++){
            if (str[id]=='0'){
                p=2*p+1;
            }else{
                p=2*p+2;
            }
            tree[p]++;
        }
    }
    int count[TreeLen];
    for (int i =0;i<TreeLen;i++){
        count[i] = tree[i];
    }
    quicksort(count, power(2, A)-1, power(2, B+1)-2);
    int treelen = power(2, B+1)-1;
    int p_c = power(2, A)-1;
    for (int n=0;n<N;n++){
        while (p_c+1<=power(2, B+1)-2 &&  count[p_c]==count[p_c+1]){
            p_c++;
        }
        int cur_count = count[p_c];
        if (count[p_c]==0){
            break;
        }
        cout<<cur_count<<endl;
        fout<<cur_count<<endl;
        int counter_inline=0;
        for (int i=power(2, A)-1;i<treelen;i++){
            if (tree[i]==cur_count){
                if (counter_inline%6!=0){
                    cout<<' ';
                    fout<<' ';
                }
                cout<<id2str(i);
                fout<<id2str(i);
                if (counter_inline%6 ==5){
                    cout<<endl;
                    fout<<endl;
                }
                counter_inline++;
            }
        }
        if (counter_inline%6!=0){
            cout<<endl;
            fout<<endl;
        }

        p_c++;
    }

    return 0;
}
