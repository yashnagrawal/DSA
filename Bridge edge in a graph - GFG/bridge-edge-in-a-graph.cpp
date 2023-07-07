//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(int node, vector<bool> &visited, vector<int> adj[]){
        visited[node] = 1;
        
        for(auto nbrNode: adj[node]){
            if(visited[nbrNode]) continue;
            
            dfs(nbrNode, visited, adj);
        }
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<bool> visited(V, 0);
        
        vector<int> new_adj[V];
        
        for(int i=0; i<V; i++){
            
            for(auto j: adj[i]){
                if((i==c&&j==d)||(i==d&&j==c)) continue;
                
                new_adj[i].push_back(j);
            }
        }
        
        dfs(c, visited, new_adj);
        
        if(visited[d]==0) return 1;
        
        return 0;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends