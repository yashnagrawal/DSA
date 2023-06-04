//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        // Your code goes here
        
        if(k>(m*n)) return -1;
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = m-1;
        
        int count = 0;
        
        while(left<=right&&top<=bottom){
            for(int j=left; j<=right; j++){
                if((++count)==k) return a[top][j];
            }
            for(int i=top+1; i<=bottom; i++){
                if((++count)==k) return a[i][right];
            }
            for(int j=right-1; j>=left; j--){
                if((++count)==k) return a[bottom][j];
            }
            for(int i=bottom-1; i>top; i--){
                if((++count)==k) return a[i][left];
            }
            top++;
            left++;
            bottom--;
            right--;
        }
        
        
        return -1;
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends