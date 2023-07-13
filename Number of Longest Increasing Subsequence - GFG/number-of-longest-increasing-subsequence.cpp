//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&arr) {
        // Code here
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        
        int no_of_subseq = 0;
        int lis_len = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[i]<=arr[j]) continue;
                
                if(dp[i]<1+dp[j]){
                    dp[i] = 1 + dp[j];
                    count[i] = count[j];
                }
                else if(dp[i] == 1 + dp[j]){
                    count[i]+=count[j];
                }
            }
            
            if(lis_len==dp[i]){
                no_of_subseq+=count[i];
            }
            else if(lis_len<dp[i]){
                no_of_subseq = count[i];
                lis_len = dp[i];
            }
        }
        
        return no_of_subseq;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends