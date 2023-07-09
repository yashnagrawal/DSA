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
	    
	    vector<long long int> dp(n);
	    
	    vector<int> last_occ_of_char(26, -1);
	    
	    dp[0] = 2;
	    last_occ_of_char[s[0]-'a'] = 0;
	    
	    for(int i=1; i<n; i++){
	        
	        if(last_occ_of_char[s[i]-'a']!=-1){
	            int j = last_occ_of_char[s[i]-'a'];
	            
	            if(j==0) dp[i] = (2ll*dp[i-1] - 1)%1000000007;
	            else dp[i] = (2ll*dp[i-1] - dp[j-1])%1000000007;
	        }
	        else{
	            dp[i] = (2ll*dp[i-1])%1000000007;
	        }
	        
	        if(dp[i]<0) dp[i]+=1000000007;
	        
	        last_occ_of_char[s[i]-'a'] = i;
	    }
	    
	    return dp[n-1];
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