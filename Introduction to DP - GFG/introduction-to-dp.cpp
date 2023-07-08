//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    unordered_map<int, long long int> dp;
  
    long long int topDown(int n) {
        // code here
        if(n<2) return n;
        
        if(dp.find(n)==dp.end()) return dp[n] = (topDown(n-1) + topDown(n-2))%1000000007;
        else return dp[n];
    }
    long long int bottomUp(int n) {
        // code here
        long long int first = 0;
        long long int second = 1;
        
        for(int i=2; i<=n; i++){
            long long int temp = second;
            
            second=(second + first)%1000000007;
            
            first = temp;
        }
        
        return second;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends