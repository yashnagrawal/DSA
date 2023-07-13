//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define mod 1003

class Solution{
public:
    int countWays(int n, string str){
        // code here
        vector<vector<int>> dp_true(n, vector<int> (n, 0)), dp_false(n, vector<int> (n, 0));
        
        for(int i=0; i<n; i++){
            if(str[i]=='T') dp_true[i][i] = 1;
            else if(str[i]=='F') dp_false[i][i] = 1;
        }
        
        for(int len=2; len<n; len=len+2){
            for(int i=0; i+len<n; i=i+2){
                int j = i + len;
                
                for(int k = i+1; k<j; k=k+2){
                    char op = str[k];
                    
                    if(op=='&'){
                        dp_true[i][j] += dp_true[i][k-1]*dp_true[k+1][j];
                        dp_false[i][j] += dp_true[i][k-1]*dp_false[k+1][j];
                        dp_false[i][j] += dp_false[i][k-1]*dp_true[k+1][j];
                        dp_false[i][j] += dp_false[i][k-1]*dp_false[k+1][j];
                    }
                    else if(op=='|'){
                        dp_true[i][j] += dp_true[i][k-1]*dp_true[k+1][j];
                        dp_true[i][j] += dp_true[i][k-1]*dp_false[k+1][j];
                        dp_true[i][j] += dp_false[i][k-1]*dp_true[k+1][j];
                        dp_false[i][j] += dp_false[i][k-1]*dp_false[k+1][j];
                    }
                    else if(op=='^'){
                        dp_false[i][j] += dp_true[i][k-1]*dp_true[k+1][j];
                        dp_true[i][j] += dp_true[i][k-1]*dp_false[k+1][j];
                        dp_true[i][j] += dp_false[i][k-1]*dp_true[k+1][j];
                        dp_false[i][j] += dp_false[i][k-1]*dp_false[k+1][j];
                    }
                    else cout<<"error: "<<i<<", "<<j<<": "<<k<<"\n";
                    
                }
                
                dp_true[i][j] %=mod;
                dp_false[i][j] %=mod;
            }
        }
        
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