//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define MOD 1003

class Solution{
public:
    int countWays(int n, string s){
        // code here
        vector<vector<int>> dp_true(n, vector<int> (n, 0)), dp_false(n, vector<int> (n, 0));
        
        for(int i=0; i<n; i++){
            if(s[i]=='T') dp_true[i][i]=1;
            else if(s[i]=='F') dp_false[i][i]=1;
        }
        
        for(int len = 1; len<n; len++){
            // cout<<"len: "<<len<<" ";
            for(int i=0; i+len<n; i++){
                int j = i+len;
                // cout<<"i: "<<i<<" j: "<<j<<" ";
                
                for(int k = i+1; k<j; k++){
                    if(s[k]=='&'){
                        dp_true[i][j]=(dp_true[i][j]+dp_true[i][k-1]*dp_true[k+1][j])%MOD;
                        
                        dp_false[i][j]=(dp_false[i][j]+dp_true[i][k-1]*dp_false[k+1][j])%MOD;
                        dp_false[i][j]=(dp_false[i][j]+dp_false[i][k-1]*dp_true[k+1][j])%MOD;
                        dp_false[i][j]=(dp_false[i][j]+dp_false[i][k-1]*dp_false[k+1][j])%MOD;
                    }
                    else if(s[k]=='|'){
                        dp_true[i][j]=(dp_true[i][j]+dp_true[i][k-1]*dp_true[k+1][j])%MOD;
                        dp_true[i][j]=(dp_true[i][j]+dp_true[i][k-1]*dp_false[k+1][j])%MOD;
                        dp_true[i][j]=(dp_true[i][j]+dp_false[i][k-1]*dp_true[k+1][j])%MOD;
                        
                        dp_false[i][j]=(dp_false[i][j]+dp_false[i][k-1]*dp_false[k+1][j])%MOD;
                    }
                    else if(s[k]=='^'){
                        dp_true[i][j]=(dp_true[i][j]+dp_true[i][k-1]*dp_false[k+1][j])%MOD;
                        dp_true[i][j]=(dp_true[i][j]+dp_false[i][k-1]*dp_true[k+1][j])%MOD;
                        
                        dp_false[i][j]=(dp_false[i][j]+dp_true[i][k-1]*dp_true[k+1][j])%MOD;
                        dp_false[i][j]=(dp_false[i][j]+dp_false[i][k-1]*dp_false[k+1][j])%MOD;
                    }
                }
            }
            // cout<<"\n";
        }
        
        // for(auto i: dp_true){
        //     for(auto j: i) cout<<j<<" ";
        //     cout<<"\n";
        // }
        
        // cout<<"\n";
        
        // for(auto i: dp_false){
        //     for(auto j: i) cout<<j<<" ";
        //     cout<<"\n";
        // }
        
        return dp_true[0][n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends