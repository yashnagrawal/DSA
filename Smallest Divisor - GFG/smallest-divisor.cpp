//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isSumOfDivOfArrLessThanEqualToK(int divisor, vector<int>&nums, int k, int n){
        if(divisor==0) return 0;
        int sum = 0;
        
        for(int i=0; i<n; i++){
            sum+=(nums[i]/divisor);
            if(nums[i]%divisor) sum++;
        }
        
        return sum<=k;
    }
    
    int smallestDivisor(vector<int>& nums, int k) {

        // Write your code here.
        int n = nums.size();
        
        int lo = 0;
        int hi = INT_MAX;
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            if(isSumOfDivOfArrLessThanEqualToK(mid, nums, k, n)) hi = mid;
            else lo = mid + 1;
        }
        
        return lo;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends