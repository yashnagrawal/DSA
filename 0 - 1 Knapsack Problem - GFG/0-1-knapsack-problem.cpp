//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int max_weight, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n, vector<int> (max_weight+1, 0));
       
       // dp[ind][weight] = max(dp[ind-1][weight], val[ind] + dp[ind-1][weight-wt[ind]]);
       
       for(int weight = wt[0]; weight<=max_weight; weight++){
           dp[0][weight] = val[0];
       }
       
       for(int ind=1; ind<n; ind++){
           for(int weight = 0; weight<=max_weight; weight++){
               dp[ind][weight] = dp[ind-1][weight];
               
               int inc_weight = weight-wt[ind];
               
               if(inc_weight>=0) dp[ind][weight] = max(dp[ind-1][weight], val[ind]+dp[ind-1][inc_weight]);
           }
       }
       
       return dp[n-1][max_weight];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends