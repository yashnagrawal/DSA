//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    vector<int> addx = {-1, 1, 0, 0};
    vector<int> addy = {0, 0, -1, 1};
    
    bool inRange(int i, int j, int n, int m){
        return i>=0&&j>=0&&i<n&&j<m;
    }
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>> min_dis(n, vector<int> (m, 0));
	    
	    queue<pair<int, int>> q;
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j]==1){
	                q.push({i, j});
	            }
	        }
	    }
	    
	    int dis = 0;
	    
	    while(!q.empty()){
	        dis++;
	        
	        int nc = q.size();
	        
	        while(nc--){
	            int i = q.front().first;
	            int j = q.front().second;
	            
	            q.pop();
	            
	            for(int k=0; k<4; k++){
	                int ni = i + addx[k];
	                int nj = j + addy[k];
	                
	                if(!inRange(ni, nj, n, m)) continue;
	                
	                if(grid[ni][nj]==0){
	                    grid[ni][nj] = 1;
	                    q.push({ni, nj});
	                    min_dis[ni][nj] = dis;
	                }
	            }
	        }
	    }
	    
	    return min_dis;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends