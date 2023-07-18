//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int lcs(string &X, string &Y, int nx, int ny){
	    vector<vector<int>> dp(nx, vector<int> (ny, 0));
	    
	    for(int i=0; i<nx; i++){
	        for(int j=0; j<ny; j++){
	            if(X[i]==Y[j]) dp[i][j] = 1 + (i&&j?dp[i-1][j-1]:0);
	            else dp[i][j] = max((i?dp[i-1][j]:0), (j?dp[i][j-1]:0));
	        }
	    }
	    
	    return dp[nx-1][ny-1];
	}
	
	int findMinCost(string X, string Y, int costX, int costY)
	{
	    // Your code goes here
	    
	    int nx = X.length();
	    int ny = Y.length();
	    
	    int lcs_len = lcs(X, Y, nx, ny);
	    
	   // cout<<lcs_len<<"\n";
	    
	    return (nx-lcs_len)*costX + (ny-lcs_len)*costY;
 	    
	}
  

};
	

//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
       	string x, y;
       	cin >> x >> y;
        
       	int costX, costY;
       	cin >> costX >> costY;

        

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends