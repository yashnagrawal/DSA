//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void recr(int col, vector<int> &arrg, vector<vector<int>> &permutations, int n){
        if(col==n){
            permutations.push_back(arrg);
            return;
        }
        
        for(int row=1; row<=n; row++){
            bool is_row_possible = 1;
            
            for(int i=0; i<col; i++){
                int q_row = arrg[i];
                
                int dx = abs(q_row-row);
                int dy = abs(i-col);
                
                if(dx==dy||dx==0||dy==0){
                    is_row_possible = 0;
                    break;
                }
            }
            
            if(!is_row_possible) continue;
            
            arrg.push_back(row);
            
            recr(col+1, arrg, permutations, n);
            
            arrg.pop_back();
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        
        vector<vector<int>> permutations;
        vector<int> arrangement;
        
        recr(0, arrangement, permutations, n);
        
        return permutations;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends