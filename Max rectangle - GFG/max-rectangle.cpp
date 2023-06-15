//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int max_rec(vector<int> arr, int n){
        int area = 0;
        vector<int> prev_smallest(n), next_smallest(n);
        stack<int> s1, s2;
        
        for(int i=0; i<n; i++){
            while(!s1.empty()&&arr[i]<=arr[s1.top()]) s1.pop();
            
            prev_smallest[i] = -1;
            if(!s1.empty()) prev_smallest[i] = s1.top();
            
            s1.push(i);
        }
        
        for(int i=n-1; i>=0; i--){
            while(!s2.empty()&&arr[i]<=arr[s2.top()]) s2.pop();
            
            next_smallest[i] = n;
            if(!s2.empty()) next_smallest[i] = s2.top();
            
            s2.push(i);
        }
        
        for(int i=0; i<n; i++){
            int curr_area = (next_smallest[i]-prev_smallest[i]-1)*arr[i];
            area = max(area, curr_area);
        }
        
        return area;
    }
    int maxArea(int mat[MAX][MAX], int n, int m) {
        // Your code here
        int area = 0;
        vector<int> arr(m, 0);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0) arr[j]=0;
                else arr[j]++;
            }
            
            int curr_area = max_rec(arr, m);
            
            area = max(area, curr_area);
        }
        
        return area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends