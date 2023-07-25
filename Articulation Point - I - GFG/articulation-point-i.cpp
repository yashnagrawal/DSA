//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, int parent, int timer, vector<int> adj[], vector<int> &time, vector<int> &low, vector<bool> &articulationPoint){
        low[node] = time[node] = timer++;
        
        int children = 0;
        
        for(auto child: adj[node]){
            if(parent==child) continue;
            
            if(time[child]==0){
                children++;
                dfs(child, node, timer, adj, time, low, articulationPoint);
                
                low[node] = min(low[node], low[child]);
                
                if(time[node]<=low[child]) articulationPoint[node] = 1;    
                
            }
            else{
                low[node] = min(low[node], time[child]);
            }
        }
        
        if(parent==-1){
            if(children>1) articulationPoint[node] = 1;
            else articulationPoint[node] = 0;
        }
    }
    
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> time(V, 0);
        vector<int> low(V, INT_MAX);
        vector<bool> articulationPoint(V, 0);
        int timer = 1;
        
        for(int i=0; i<V; i++){
            if(time[i]==0) dfs(i, -1, 1, adj, time, low, articulationPoint);
        }
        
        vector<int> nodes;
        
        for(int i=0; i<V; i++){
            if(articulationPoint[i]) nodes.push_back(i);
        }
        
        if(nodes.size()==0) nodes.push_back(-1);
        
        return nodes;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends