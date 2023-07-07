//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet{
    private:
    vector<int> parent;
    vector<int> size;
    
    public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n, 1);
        
        for(int i=0; i<n; i++) parent[i] = i;
    }
    
    int findUParent(int node){
        if(node==parent[node]) return node;
        
        return parent[node] = findUParent(parent[node]);
    }
    
    void unionSet(int node1, int node2){
        int parent1 = findUParent(node1);
        int parent2 = findUParent(node2);
        
        if(parent1==parent2) return;
        
        int size1 = size[parent1];
        int size2 = size[parent2];
        
        if(size1<size2){
            parent[parent1] = parent2;
            size[parent2]+=size1;
        }
        
        else{
            parent[parent2] = parent1;
            size[parent1]+=size2;
        }
    }
    
    int findSize(int node){
        return size[node];
    }
};

class Solution {
  public:
    vector<int> addx = {-1, 1, 0, 0};
    vector<int> addy = {0, 0, 1, -1};
    
    int coordinatesToNode(int x, int y, int m){
        return x*m+y;
    }
    
    bool inRange(int x, int y, int n, int m){
        return x>=0&&y>=0&&x<n&&y<m;
    }
    
    void connectIslands(int x, int y, vector<vector<int>>& grid, int n, int m, DisjointSet &ds){
        grid[x][y] = 1;
        
        int node1 = coordinatesToNode(x, y, m);
        
        for(int k=0; k<4; k++){
            int nx = x + addx[k];
            int ny = y + addy[k];
            
            if(!inRange(nx, ny, n, m)||!grid[nx][ny]) continue;
            
            int node2 = coordinatesToNode(nx, ny, m);
            
            ds.unionSet(node1, node2);
        }
    }
    
    int islandSizeAfterUnion(int x, int y, vector<vector<int>>& grid, int n, int m, DisjointSet &ds){
        int size = 1;
        
        unordered_set<int> nodes;
        
        for(int k=0; k<4; k++){
            int nx = x + addx[k];
            int ny = y + addy[k];
            
            if(!inRange(nx, ny, n, m)||!grid[nx][ny]) continue;
            
            int node = coordinatesToNode(nx, ny, m);
            int parent = ds.findUParent(node);
            
            if(nodes.find(parent)!=nodes.end()) continue;
            
            nodes.insert(parent);
            
            size+=ds.findSize(parent);
        }
        
        return size;
    }
    
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        DisjointSet ds = DisjointSet(m*n);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0) continue;
                
                connectIslands(i, j, grid, n, m, ds);
            }
        }
        
        int biggestIsland = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int curr_size;
                if(!grid[i][j]){
                    curr_size = islandSizeAfterUnion(i, j, grid, n, m, ds);
                }
                else{
                    int node = coordinatesToNode(i, j, m);
                    curr_size = ds.findSize(node);
                }
                
                biggestIsland = max(biggestIsland, curr_size);
            }
        }
        
        
        return biggestIsland;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends