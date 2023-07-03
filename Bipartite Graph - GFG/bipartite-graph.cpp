//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V, -1);
	    
	    queue<int> q;
	    
	    for(int i=0; i<V; i++){
	        if(color[i]!=-1) continue;
	        
	        q.push(i);
	        
	        int clr = 0;
	        
	        color[i] = clr;
	    
    	    while(!q.empty()){
    	        
    	        int nc = q.size();
    	        clr = (clr+1)%2;
    	        
    	        while(nc--){
    	            int front = q.front();
    	            q.pop();
    	            
    	            for(auto child: adj[front]){
    	                if(color[child]==-1){
    	                    color[child] = clr;
    	                    q.push(child);
    	                }
    	                
    	                else if(color[child]!=clr) return false;
    	            }
    	        }
    	    }
	    }
	    
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends