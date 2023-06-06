//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int subsetXOR(vector<int> arr, int n, int k) {
        // code here
        
        vector<vector<int>> dp(n+1, vector<int> (128, 0));
        
        dp[0][0]=1;
        
        for(int i=1; i<=n; i++){
            
            for(int j=0; j<128; j++){
                dp[i][j]=dp[i-1][j];
                int sub_xor = j^arr[i-1];
                if(sub_xor<128) dp[i][j]+=dp[i-1][sub_xor];
            }
        }
        
        // for(int i=0; i<=n; i++){
        //     for(int j=0; j<=k; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        
        return dp[n][k];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends