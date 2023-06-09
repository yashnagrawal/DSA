//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int number_of_hours(vector<int> &piles, int speed){
        int ans = 0;
        
        for(auto bananas: piles){
            ans+=bananas/speed;
            if(bananas%speed) ans++;
        }
        
        return ans;
    }
    
    
    int Solve(int n, vector<int>& piles, int h) {
        // Code here
        int lo = 0;
        int hi = INT_MAX;
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            if(number_of_hours(piles, mid)<=h) hi = mid;
            else lo = mid + 1;
        }
        
        return lo;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends