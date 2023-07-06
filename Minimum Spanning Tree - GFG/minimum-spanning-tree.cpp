//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int findParent(int parent[], int node){
	    if(node == parent[node]) return node;
	    
	    return parent[node] = findParent(parent, parent[node]);
	}
	
	bool unionSet(int parent[], int size[], int node1, int node2){
	    int parent1 = findParent(parent, node1);
	    int parent2 = findParent(parent, node2);
	    
	    if(parent1==parent2) return false;
	    
	    if(size[parent1]<size[parent2]){
	        size[parent2]+=size[parent1];
	        parent[parent1] = parent2;
	    }
	    else if(size[parent2]<size[parent1]){
	        size[parent1]+=size[parent2];
	        parent[parent2] = parent1; 
	    }
	    
	    else{
	        size[parent1]+=size[parent2]+1;
	        parent[parent2] = parent1; 
	    }
	    
	    return true;
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int, pair<int, int>>,
                        vector<pair<int, pair<int, int>>>,
                        greater<pair<int, pair<int, int>>>> pq;
        
        int parent[V];
        int size[V];
        
        for(int i=0; i<V; i++){
            parent[i] = i;
            size[i] = 0;
        }
        
        for(int i=0; i<V; i++){
            int node1 = i;
            
            for(auto vtr: adj[node1]){
                int node2 = vtr[0];
                int weight = vtr[1];
                
                pq.push({weight, {node1, node2}});
            }
        }
        
        int sum = 0;
        
        while(!pq.empty()){
            int node1 = pq.top().second.first;
            int node2 = pq.top().second.second;
            
            int weight = pq.top().first;
            
            pq.pop();
            
            int parent1 = findParent(parent, node1);
            int parent2 = findParent(parent, node2);
            
            if(unionSet(parent, size, parent1, parent2)) sum+=weight;
        }
        
        return sum;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends