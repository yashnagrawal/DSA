//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int timer = 1;
    void dfs(int node, int parent, vector<int>adj[], vector<int> &time, vector<int> &low, vector<int> &articulationNodes){
        time[node] = timer;
        low[node] = timer++;
        
        int children = 0;
        
        bool isArticulation = 0;
        
        for(auto nbrNode: adj[node]){
            if(parent==nbrNode) continue;
            
            if(time[nbrNode]==0){
                children++;
                dfs(nbrNode, node, adj, time, low, articulationNodes);
                
                low[node] = min(low[node], low[nbrNode]);
                
                if(low[nbrNode]>=time[node]) isArticulation = 1;
            }
            
            else{
                low[node] = min(low[node], time[nbrNode]);
            }
        }
        
        if(parent!=-1){
            if(isArticulation) articulationNodes.push_back(node);
        }
        else{
            if(children>1) articulationNodes.push_back(node);
        }
        
    }
    
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> time(V, 0);
        vector<int> low(V, INT_MAX);
        vector<int> articulationNodes;
        
        for(int i=0; i<V; i++){
            if(time[i]==0) dfs(i, -1, adj, time, low, articulationNodes);
        }
        
        sort(articulationNodes.begin(), articulationNodes.end());
        
        if(articulationNodes.size()==0) articulationNodes.push_back(-1);
        
        return articulationNodes;
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