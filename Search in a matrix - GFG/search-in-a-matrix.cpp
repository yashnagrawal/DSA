//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    
	int matSearch (vector <vector <int>> &mat, int n, int m, int x)
	{
	    // your code here
	    
	    if(mat[0][0]>x||mat[n-1][m-1]<x) return 0;
	    
	    int row = 0;
	    int col = m-1;
	    
	    while(row<n&&col<m){
	       // cout<<"row: "<<row<<", col: "<<col<<"\n";
	        if(mat[row][col]==x) return 1;
	        else if(x>mat[row][col]) row++;
	        else col--;
	    }
	    
	    
	    return 0;
	}
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends