//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n = s.length();
	    vector<long long> dp(n+1, 1);
	    //dp[i] a[i-1]
	    
	    for(int i=1; i<=n; i++){
	        dp[i]=(2*dp[i-1])%1000000007;
	        int k;
	        for(k=i-1; k>0; k--){
	            if(s[i-1]==s[k-1]) break;
	        }
	        
	        if(k>0){
	            dp[i]=(2*dp[i-1]-dp[k-1]+1000000007)%1000000007;
	        }
	    }
	    
	    return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends