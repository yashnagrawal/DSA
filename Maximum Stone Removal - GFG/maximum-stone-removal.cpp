//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet{
    private:
    vector<int> parent;
    vector<int> size;
    
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 0);
        
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    
    int findUParent(int node){
        if(parent[node]==node) return node;
        
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
            size[parent2]+=size1+1;
        }
        
        else{
            parent[parent2] = parent1;
            size[parent1]+=size2+1;
        }
    }
};

class Solution {
  public:
    
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        unordered_set<int> stoneNodes;
        
        int maxRow = 0, maxCol = 0;
        
        for(auto itr: stones){
            maxRow = max(maxRow, itr[0]);
            maxCol = max(maxCol, itr[1]);
        }
        
        DisjointSet ds = DisjointSet(maxRow + maxCol + 1);
        
        for(int i=0; i<n; i++){
            int row = stones[i][0];
            int col = stones[i][1]+1+maxRow;
            
            ds.unionSet(row, col);
            
            stoneNodes.insert(row);
            stoneNodes.insert(col);
        }
        
        int removable_stones = n;
        
        for(auto node: stoneNodes){
            if(node==ds.findUParent(node)) removable_stones--;
        }
        
        return removable_stones;
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
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends