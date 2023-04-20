//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string s, int n){
        for(int i=0; i<n; i++){
            if(s[i]!=s[n-i-1]) return false; 
        }
        
        return true;
    }
    
    int palindromicPartition(string s)
    {
        // code here
        int n = s.length();
        
        vector<vector<int>> dp(n, vector<int> (n, 1));
        
        for(int i=0; i<n; i++) dp[i][i]=1;
        
        for(int len=1; len<n; len++){
            for(int i=0; i+len<n; i++){
                int j = i+len;
                int ans = INT_MAX;
                
                if(isPalindrome(s.substr(i, j-i+1), j-i+1)) continue;
                
                for(int k=i; k<j; k++){
                    ans=min(ans, dp[i][k]+dp[k+1][j]);
                }
                dp[i][j]=ans;
            }
        }
        
        // cout<<"  ";
        // for(auto i: s) cout<<i<<" ";
        // cout<<"\n";
        
        // for(int i=0; i<n; i++){
        //     cout<<s[i]<<" ";
        //     for(int j=0; j<n; j++) cout<<dp[i][j]<<" ";
        //     cout<<"\n";
        // }
        
        return dp[0][n-1]-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends