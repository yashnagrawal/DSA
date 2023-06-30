//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int prefix_xor(int n){
        int mod = n%4;
        
        if(mod==1) return 1;
        if(mod==2) return n+1;
        if(mod==3) return 0;
        
        return n;
    }
    int findXOR(int l, int r) {
        // complete the function here
        
        // 1: 1
        // 3: 1^2
        // 0: 1^2^3
        // 4: 1^2^3^4
        // 1: 1^2^3^4^5
        
        return prefix_xor(r)^prefix_xor(l-1);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends