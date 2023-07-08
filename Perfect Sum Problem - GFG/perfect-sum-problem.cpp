//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n, vector<int> (sum+1, 0));
        
        dp[0][0] = 1;
        dp[0][arr[0]]++;
        
        for(int i=1; i<n; i++){
            for(int target=0; target<=sum; target++){
                dp[i][target] = dp[i-1][target];
                
                if(target-arr[i]>=0) dp[i][target] = (dp[i][target] + dp[i-1][target-arr[i]])%1000000007;
            }
        }
        
        return dp[n-1][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends