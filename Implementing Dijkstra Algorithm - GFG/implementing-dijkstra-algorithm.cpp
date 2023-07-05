//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V, INT_MAX);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(V, 0);
        
        pq.push({0, S});
        dist[S] = 0;
        visited[S] = 1;
        
        while(!pq.empty()){
            int node = pq.top().second;
            visited[node] = 1;
            pq.pop();
            
            for(auto vtr: adj[node]){
                int child = vtr[0];
                int new_dis = vtr[1] + dist[node];
                
                if(visited[child]) continue;
                
                if(dist[child]>new_dis){
                    dist[child] = new_dis;
                    
                    pq.push({new_dis, child});
                }
            }
        }
        
        for(int i=0; i<V; i++){
            if(dist[i]==INT_MAX) dist[i] = -1;
        }
        
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends