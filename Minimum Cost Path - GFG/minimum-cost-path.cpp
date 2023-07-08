//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define newPair pair<int, pair<int, int>>

class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	bool inRange(int x, int y, int n){
	    return x>=0&&y>=0&&x<n&&y<n;
	}
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();
        
        vector<vector<int>> cost(n, vector<int> (n, INT_MAX));
        vector<int> addx = {-1, 1, 0, 0};
        vector<int> addy = {0, 0, -1, 1};
        
        cost[0][0] = grid[0][0];
        
        priority_queue<newPair,
                        vector<newPair>,
                        greater<newPair>> pq;
        
        pq.push({cost[0][0], {0, 0}});
        
        while(!pq.empty()){
            int min_cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            
            if(min_cost>cost[x][y]) continue;
            
            for(int k=0; k<4; k++){
                int new_x = x + addx[k];
                int new_y = y + addy[k];
                if(!inRange(new_x, new_y, n)) continue;
                
                int new_cost = min_cost + grid[new_x][new_y];
                
                if(new_cost>=cost[new_x][new_y]) continue;
                
                cost[new_x][new_y] = new_cost;
                pq.push({new_cost, {new_x, new_y}});
            }
        }
        
        return cost[n-1][n-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends