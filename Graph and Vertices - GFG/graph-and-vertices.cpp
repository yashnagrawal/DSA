//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long pow(long long a, int b){
        if(b==0) return 1;
        
        long long ans = pow(a, b/2);
        
        ans*=ans;
        
        if(b%2) ans*=a;
        
        return ans;
    }
  
    long long count(int n) {
        // your code here
        
        return pow(2, (n*(n-1))/2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.count(n) << "\n";
    }

    return 0;
}

// } Driver Code Ends