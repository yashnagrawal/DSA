//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int max_jumps[], int n) {
        // code here
        
        int pos = 0;
        
        while(pos<n){
            // cout<<pos<<"\n";
            int max_range_ind = pos;
            
            for(int i=pos+1; i<n&&i<=pos+max_jumps[pos]; i++){
                int range_here = i + max_jumps[i];
                int max_range = max_range_ind + max_jumps[max_range_ind];
                
                if(max_range<=range_here) max_range_ind = i;
            }
            
            if(max_range_ind==pos) break;
            pos = max_range_ind;
        }
        
        
        return pos + max_jumps[pos]>= n-1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends