//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxChildren(int n, int m, vector<int> &greed, vector<int> &sz) {
        // code here
        sort(greed.begin(), greed.end());
        sort(sz.begin(), sz.end());
        
        int children = 0;
        
        int cookie_ind = 0;
        
        for(int i=0; i<n; i++){
            while(cookie_ind<m&&greed[i]>sz[cookie_ind]) cookie_ind++;
            
            if(cookie_ind<m){
                cookie_ind++;
                children++;
            } 
            else break;
        }
        
        return children;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<int> greed(N), sz(M);
        for (int i = 0; i < N; i++) {
            cin >> greed[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> sz[i];
        }
        Solution obj;
        cout << obj.maxChildren(N, M, greed, sz) << endl;
    }
    return 0;
}
// } Driver Code Ends