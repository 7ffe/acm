#include <iostream>
using namespace std;
const int N = 2000000001;
//bool touched[N];


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
        if (data[i]<midv){
            swap(data[i], data[store]);
            store++;
        }
    }
    swap(data[store], data[tail]);

    quicksort(data, head, store-1);
    quicksort(data, store+1, tail);
    return 0;
}

bool found;
int min_remain;
int m;
int n[4];
int v[4][300];

int search(int depth, int res){
    if (depth ==4){
        if (res>=0 && res<min_remain){
            min_remain = res;
        }
    }else if (depth ==3){
        int left = 0, right = n[3]-1, mid;
        while (left <right){
            mid = (left+right)/2;
            if (v[3][mid]<res){
                left  = mid;
            }
            else{
                right = mid;
            }
        }
        if (res>=v[3][left]){
            search(4, res-v[3][left]);
        }


    }else{
        for (int i=0;i<n[depth]; i++){

            if (res>=v[depth][i]){
                search(depth+1, res-v[depth][i]);

            }else{
                break;
            }
        }
    }
}

int main(){
    int z;
    cin>>z;

    while (z--){
        cin>>m;
        for (int i=0;i<4;i++){
            cin>>n[i];
            for (int j=0;j<n[i];j++)
                cin>>v[i][j];
            quicksort(v[i], 0, n[i]-1);
        }
        if (v[0][0]+v[1][0]+v[2][0]+v[3][0] > m){
            cout<<-1<<endl;
            continue;
        }
        found=false;
        min_remain = m;
        //search(0, m);

        int vv1[90000], vv2[90000];
        int l1=0, l2=0;
        for (int i = 0;i<n[0];i++)
            for (int j=0;j<n[1];j++)
                vv1[l1++] = v[0][i] + v[1][j];
        for (int i = 0;i<n[2];i++)
            for (int j=0;j<n[3];j++)
                vv2[l2++] = v[2][i] + v[3][j];
        quicksort(vv1, 0, l1-1);
        quicksort(vv2, 0, l2-1);
        //cout<<"hi"<<l2<<endl;
        for (int i=0;i<l1;i++) if (m>=vv1[i]+vv2[0]){

            int left = 0, right = l2-1, mid;
            while (left <right-1){
                //cout<<"hi";
                mid = (left+right)/2;
                //cout<<left<<right<<' '<<vv2[left]<<' '<<vv2[right]<< ' '<<m<<' '<< vv1[i]<<endl;
                if (vv1[i]+vv2[mid]<m){
                    left  = mid;
                }
                else{
                    right = mid;
                }
            }
            if (m-vv1[i]-vv2[left]>=0 && m-vv1[i]-vv2[left]<min_remain)
                min_remain = m-vv1[i]-vv2[left];
            if (m-vv1[i]-vv2[right]>=0 && m-vv1[i]-vv2[right]<min_remain)
                min_remain = m-vv1[i]-vv2[right];
        }



        cout<<m-min_remain<<endl;

    }

}
