/*
ID: silasli2
PROG: humble
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int isHumble(int prime[], int k, int m){
    for (int i =0;i<k;i++){
        while (m%prime[i]==0){
            m/=prime[i];
        }
    }
    return (m==1);
}
int min2(int a, int b){
    if (a<b){
        return a;
    }else{
        return b;
    }
}

int main() {
    ofstream fout ("humble.out");
    ifstream fin ("humble.in");
    const int K = 100;
    const int N = 100000;
    int k,n;
    fin>>k>>n;
    int prime[K];
    int humble[N+1];
    humble[0]=1;
    for (int i = 0;i<k;i++){
        fin>>prime[i];
    }
    int count=0;
    /*
    int m=1;
    while (count<n){
        m++;
        while (!isHumble(prime, k, m)){
            m++;
        }
        count++;
    }*/
    /*
    int start=0;
    while (count<n){
        int min_hum = 2147483647;
        for (int i = start;i<=count;i++){
            for (int j = 0;j<k;j++){
                if (humble[i]*prime[j]>humble[count] && humble[i]*prime[j]<min_hum){

                    min_hum = humble[i]*prime[j];
                    break;
                }
            }
        }
        count++;
        humble[count]= min_hum;
        while (humble[count]/prime[k-1]>humble[start]){
            start++;
        }
    }*/
    int pos[K];
    int gene[K];
    for (int i = 0;i<k;i++){
        pos[i]=0;
        gene[i]=prime[i];
    }


    while(count<n){
        int gene_min=2147483647;
        int prime_id;
        for (int i =0;i<k;i++){
            if (gene[i]<gene_min){
                gene_min=gene[i];
                prime_id=i;
            }else if (gene[i]==gene_min){
                pos[i]++;
                gene[i]=humble[pos[i]]*prime[i];
            }
        }
        count++;
        humble[count]= gene_min;
        pos[prime_id]++;
        gene[prime_id]=humble[pos[prime_id]]*prime[prime_id];
    }

    for (int i =0;i<=n;i++){
        cout<<humble[i]<<' ';
    }
    cout<<endl;
    cout<<humble[n]<<endl;
    fout<<humble[n]<<endl;
    return 0;
}
