//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        // Your code goes here
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            if(i>0&&nums[i]==nums[i-1]) continue;

            for(int j=i+1; j<n; j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                
                int st = j+1;
                int ed = n-1;

                while(st<ed){
                    long long int curr_sum = (long long int)nums[i]+nums[j]+nums[st]+nums[ed];
                    if(curr_sum>target) ed--;
                    else if(curr_sum<target) st++;
                    else{
                        ans.push_back({nums[i], nums[j], nums[st], nums[ed]});
                        st++;
                        ed--;
                        while(st<ed&&nums[st]==nums[st-1]) st++;
                        while(st<ed&&nums[ed]==nums[ed+1]) ed--;
                    }
                }
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends