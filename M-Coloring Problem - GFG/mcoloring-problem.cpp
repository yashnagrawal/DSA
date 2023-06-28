//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool recr(int node, bool graph[101][101], int m, int n, vector<int> &color){
        if(node == n) return true;
        
        for(int clr = 0; clr<m; clr++){
            bool is_clr_possible = 1;
            
            for(int nbr=0; nbr<n; nbr++){
                if(graph[node][nbr]==0) continue;
                
                if(color[nbr]==clr){
                    is_clr_possible = 0;
                    break;
                }
            }
            
            if(!is_clr_possible) continue;
            
            color[node] = clr;
            if(recr(node+1, graph, m, n, color)) return true;
        }
        
        color[node] = -1;
        
        return false;
        
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        
        vector<int> color(n, -1);
        
        return recr(0, graph, m, n, color);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends