//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    int min_diff = INT_MAX;
	    
	    for(int i=0; i<n; i++) sum+=arr[i];
	    
	    vector<vector<bool>> dp(n, vector<bool> (sum+1, 0));
	    
	    dp[0][arr[0]] = 1;
	    dp[0][0] = 1;
	    
	    for(int i=1; i<n; i++){
	        for(int j=0; j<=sum; j++){
	            dp[i][j] = dp[i-1][j];
	            
	            if(j-arr[i]>=0) dp[i][j] = dp[i][j] || dp[i-1][j-arr[i]];
	        }
	    }
	    
	    for(int curr_sum = 0; curr_sum<=sum; curr_sum++){
	        if(!dp[n-1][curr_sum]) continue;
	        
	        int curr_diff = abs(sum-(2*curr_sum));
	        
	        min_diff = min(min_diff, curr_diff);
	    }
	    
	    return min_diff;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends