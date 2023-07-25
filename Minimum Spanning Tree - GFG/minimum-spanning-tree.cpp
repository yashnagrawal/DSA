//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    typedef pair<int, int> iPair;
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        vector<bool> visited(V, 0);
        int ans = 0;
        
        // weight , node
        pq.push(make_pair(0, 0));
        
        while(!pq.empty()){
            auto top = pq.top();
            int u = top.second;
            // cout<<u<<": ";
            pq.pop();
            
            if(visited[u]) continue;
            
            ans += (top.first);
            visited[u] = 1;
            // cout<<" "<<(top.first)<<" added || ";
            
            for(auto i: adj[u]){
                int v = i[0];
                int w = i[1];
                if(!visited[v]){
                    // cout<<w<<", "<<v<<"; ";
                    pq.push(make_pair(w, v));
                }
            }
            // cout<<"\n";
        }
        return ans;
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