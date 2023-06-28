// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void recr(int i, int j, int n, string str, vector<vector<int>> &m, vector<string> &paths){
        if(i==n-1&&j==n-1){
            paths.push_back(str);
        }
        
        m[i][j]=0;
        
        if(i<n-1&&m[i+1][j]==1) recr(i+1, j, n, str+"D", m, paths);
        if(j>0&&m[i][j-1]==1) recr(i, j-1, n, str+"L", m, paths);
        if(j<n-1&&m[i][j+1]==1) recr(i, j+1, n, str+"R", m, paths);
        if(i>0&&m[i-1][j]==1) recr(i-1, j, n, str+"U", m, paths);
        
        m[i][j]=1;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> paths;
        
        if(m[0][0]==0||m[n-1][n-1]==0) return paths; 
        
        recr(0, 0, n, "", m, paths);
        
        return paths;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends