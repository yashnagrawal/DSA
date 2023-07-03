//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> addx = {-1, 1, 0, 0};
    vector<int> addy = {0, 0, -1, 1};
    
    bool inRange(int i, int j, int n, int m){
        return i>=0&&j>=0&&i<n&&j<m;
    }
    
    void dfs(int i, int j, vector<vector<char>> &new_mat, int n, int m){
        new_mat[i][j] = 'S';
        
        for(int k=0; k<4; k++){
            int ni = i + addx[k];
            int nj = j + addy[k];
            
            if(!inRange(ni, nj, n, m)) continue;
            
            if(new_mat[ni][nj]=='O') dfs(ni, nj, new_mat, n, m);
        }
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<char>> new_mat = mat;
        
        for(int i=0; i<n; i++){
            if(new_mat[i][0]=='O') dfs(i, 0, new_mat, n, m);
            if(new_mat[i][m-1]=='O') dfs(i, m-1, new_mat, n, m);
        }
        
        for(int j=0; j<m; j++){
            if(new_mat[0][j]=='O') dfs(0, j, new_mat, n, m);
            if(new_mat[n-1][j]=='O') dfs(n-1, j, new_mat, n, m);
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(new_mat[i][j]=='O') new_mat[i][j] = 'X';
                
                if(new_mat[i][j]=='S') new_mat[i][j] = 'O';
                
            }
        }
        
        return new_mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends