//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMatching(string text, string pat) {
        // Code here
        int nt = text.length();
        int np = pat.length();
        
        for(int i=0; i<=nt-np; i++){
            
            bool isIndPat = 1;
            
            for(int j=0; j<np; j++){
                if(text[i+j]!=pat[j]){
                    isIndPat = 0;
                    break;
                }
            }
            
            if(isIndPat) return i;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string text, pat;
        cin >> text >> pat;
        Solution obj;
        cout << obj.findMatching(text, pat) << endl;
    }
    return 0;
}
// } Driver Code Ends