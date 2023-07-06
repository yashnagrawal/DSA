//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findUParent(vector<int> &parent, int ind){
        if(parent[ind]==ind) return ind;
        
        return parent[ind] = findUParent(parent, parent[ind]);
    }
    
    void unionSet(vector<int> &parent, vector<int> &size, int ind1, int ind2){
        
        int parent1 = findUParent(parent, ind1);
        int parent2 = findUParent(parent, ind2);
        
        if(parent1==parent2) return;
        
        int size1 = size[parent1];
        int size2 = size[parent2];
        
        if(size1<size2){
            parent[parent1] = parent2;
            
            size[parent2]+=size[parent1]+1;
        }
        
        else if(size1>size2){
            parent[parent2] = parent1;
            
            size[parent1]+=size[parent2]+1;
        }
        
        else{
            parent[parent2] = parent1;
            
            size[parent1]+=size[parent2]+1;
        }
    }
    
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        unordered_map<int, vector<int>> rows, cols;
        
        vector<int> parent(n), size(n, 0);
        
        for(int i=0; i<n; i++){
            int row = stones[i][0];
            int col = stones[i][1];
            
            rows[row].push_back(i);
            cols[col].push_back(i);
            
            parent[i] = i;
        }
        
        for(auto pr: rows){
            int npr = pr.second.size();
            
            for(int i=1; i<npr; i++){
                unionSet(parent, size, pr.second[0], pr.second[i]);
            }
        }
        
        for(auto pr: cols){
            int npr = pr.second.size();
            
            for(int i=1; i<npr; i++){
                unionSet(parent, size, pr.second[0], pr.second[i]);
            }
        }
        
        int removable_stones = 0;
        
        for(int i=0; i<n; i++){
            int prnt = findUParent(parent, i);
            
            removable_stones+=size[prnt];
            
            size[prnt] = 0;
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