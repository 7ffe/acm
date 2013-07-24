// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;

int main() {
    // Start typing your code here...
    int n;
    string data;
    cin>>n;
    cin>>data;
    int ans = 0;
    for (int i=n;i<data.size();i+=n){
        if (data[i-1]==data[i-2] && data[i-2]==data[i-3])
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
