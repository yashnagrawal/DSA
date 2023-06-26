//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isGoodNum(int num, int d){
        int sum = num%10;
        num/=10;
        
        if(sum==d) return 0;
        
        while(num>0){
            int digit = num%10;
            num/=10;
            
            if(digit<=sum||digit==d) return 0;
            sum+=digit;
        }
        
        return 1;
    }
    vector<int> goodNumbers(int l, int r, int d) {
        // code here
        vector<int> ans;
        
        for(int i=l; i<=r; i++){
            if(isGoodNum(i, d)) ans.push_back(i);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends