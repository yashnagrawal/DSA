//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int num_of_elements_greater_than_x(vector<vector<int>> &mat, int m, int n, int x){
        int ans = 0;
        
        for(int i=0; i<m; i++){
            int lo =  0;
            int hi = n;
            
            while(lo<hi){
                int mid = lo + (hi-lo)/2;
                
                if(mat[i][mid]>x) hi = mid;
                else lo = mid + 1;
            }
            
            ans+=(n-lo);
        }
        
        return ans;
    }
    
    int median(vector<vector<int>> &mat, int m, int n){
        // code here    
        int lo = INT_MAX;
        int hi = INT_MIN;
        int limit = (m*n)/2;
        
        for(int i=0; i<m; i++){
            lo = min(lo, mat[i][0]);
            hi = max(hi, mat[i][n-1]);
        }
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            if(num_of_elements_greater_than_x(mat, m, n, mid)<=limit) hi = mid;
            else lo = mid + 1;
        }
        
        return lo;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends