//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int lcs_finder(string &str1, string &str2, int n1, int n2){
	    vector<vector<int>> dp(n1, vector<int> (n2, 0));
	    
	    for(int i=0; i<n1; i++){
	        for(int j=0; j<n2; j++){
	            if(str1[i]==str2[j]) dp[i][j] = 1 + (i&&j?dp[i-1][j-1]:0);
	            else dp[i][j] = max((i?dp[i-1][j]:0), (j?dp[i][j-1]:0));
	        }
	    }
	    
	    return dp[n1-1][n2-1];
	}
	
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n1 = str1.length();
	    int n2 = str2.length();
	    
	    int lcs = lcs_finder(str1, str2, n1, n2);
	    
	    int deletions = n1-lcs;
	    int insertions = n2-lcs;
	    
	    return deletions + insertions;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends