//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int atMaxKSubarrays(int n, vector<int> &nums, int k){
        int j = 0;
        int ans = 0;
        
        for(int i=0; i<n; i++){
            if(nums[i]%2) k--;
            
            while(k<0){
                if(nums[j]%2) k++;
                j++;
            }
            
            ans+=(i-j+1);
            
        }
        
        return ans;
    }
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        return atMaxKSubarrays(n, nums, k) - atMaxKSubarrays(n, nums, k-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends