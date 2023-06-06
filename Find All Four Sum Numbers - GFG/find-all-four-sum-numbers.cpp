//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int st = 0;
                int ed = n-1;
                
                while(st<i&&j<ed){
                    int curr_sum = arr[st]+arr[i]+arr[j]+arr[ed];
                    
                    if(curr_sum==k){
                        // cout<<st<<", "<<i<<", "<<j<<", "<<ed<<"\n";
                        s.insert({arr[st], arr[i], arr[j], arr[ed]});
                        st++;
                        ed--;
                    }
                    
                    else if(curr_sum>k) ed--;
                    
                    else st++;
                }
            }
        }
        
        for(auto i: s) ans.push_back(i);
        
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