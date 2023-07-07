//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define newPair pair<int, pair<int, int>>
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
        if(parent[node]==node) return node;
        
        return parent[node] = findUParent(parent[node]);
    }
    
    void unionSet(int node1, int node2){
        int parent1 = findUParent(node1);
        int parent2 = findUParent(node2);
        
        if(parent1==parent2) return;
        
        if(size[parent1]<size[parent2]){
            parent[parent1] = parent2;
            size[parent2]+=size[parent1];
        }
        else{
            parent[parent2] = parent1;
            size[parent1]+=size[parent2];
        }
    }
};

class Solution {
  public:
    vector<int> addx = {-1, 1, 0, 0};
    vector<int> addy = {0, 0, -1, 1};
    
    bool inRange(int x, int y, int n){
        return x>=0&&y>=0&&x<n&&y<n;
    }
    
    int coordinatesToNode(int x, int y, int n){
        return x*n+y;
    }
    
    void addToSet(int x, int y, int t, vector<vector<int>>& grid, int n, DisjointSet &ds){
        int node = coordinatesToNode(x, y, n);
        
        for(int k=0; k<4; k++){
            int nx = x + addx[k];
            int ny = y + addy[k];
            
            if(!inRange(nx, ny, n)||grid[nx][ny]>t) continue;
            
            int new_node = coordinatesToNode(nx, ny, n);
            
            ds.unionSet(node, new_node);
        }
    }
    
    int Solve(int n, vector<vector<int>>& grid) {
        // code here
        
        int st = max(grid[n-1][n-1], grid[0][0]);
        int et = 0;
        
        DisjointSet ds = DisjointSet(n*n); 
        
        priority_queue<newPair, 
                        vector<newPair>,
                        greater<newPair>> pq;
                        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                pq.push({grid[i][j], {i, j}});
                et = max(et, grid[i][j]);
            }
        }
        
        for(int t=st; t<=et; t++){
            while(!pq.empty()&&pq.top().first<=t){
                int x = pq.top().second.first;
                int y = pq.top().second.second;
                
                pq.pop();
                addToSet(x, y, t, grid, n, ds);
            }
            
            int first_node = coordinatesToNode(0, 0, n);
            int last_node = coordinatesToNode(n-1, n-1, n);
            
            if(ds.findUParent(first_node)==ds.findUParent(last_node)) return t;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < n; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends