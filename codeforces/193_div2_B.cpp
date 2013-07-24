// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include <stdio.h>
using namespace std;

long long data[200010], rightmax[200010], subsum[200010], rightpos[200010];

int main() {
    // Start typing your code here...
    int n, k, tmp;
    int ans_a, ans_b=n;
    long long ans;
    scanf("%d%d", &n, &k);
    for (int i = 0;i<n;i++){
        scanf("%d", &tmp);
        data[i] = tmp;
        //scanf("%lld", &data[i]);
    }
    subsum[0] = 0;
    for (int i=0;i<k;i++)
        subsum[0] += data[i];
    for (int i=1;i<=n-k;i++){
        subsum[i] = subsum[i-1] - data[i-1] + data[i+k-1];
        //cout<<subsum[i]<<" ";
    }
    rightmax[n-1-(k-1)] = subsum[n-k];
    rightpos[n-1-(k-1)] = n-k;
    for (int i=n-k-1;i>=0;i--){
        if (subsum[i] >= rightmax[i+1]){
            rightmax[i] = subsum[i];
            rightpos[i] = i;
        }else{
            rightmax[i] = rightmax[i+1];
            rightpos[i] = rightpos[i+1];
        }
    }
    long long leftmax = subsum[0];
    ans = subsum[0] + subsum[k];
    ans_a = 0;
    ans_b = k;
    int leftpos = 0;
    for (int a=0;a<n;a++){
        if (a+k<=n && subsum[a]>leftmax){
            leftpos = a;
            leftmax = subsum[a];
            
        }
        if (a+k <= n-k){
            if (leftmax + rightmax[a+k] > ans){
                ans = leftmax + rightmax[a+k];
                ans_a  = leftpos;
                ans_b  = rightpos[a+k];
            }
        }
            
    }
    //for (int i=0;i<n-k;i++)
        //printf("%d ", rightmax[i]);
    //printf("\n");
    printf("%d %d\n", ans_a+1, ans_b+1);
    
    return 0;
}
