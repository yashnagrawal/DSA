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
        
        vector<int> lps(np, 0);
        
        for(int i=1; i<np; i++){
            int j = lps[i-1];
            
            while(j&&pat[i]!=pat[j]) j = lps[j-1];
            
            if(pat[i]==pat[j]) j++;
            
            lps[i] = j;
        }
        
        int j = 0;
        
        for(int i=0; i<nt; i++){
            
            while(j>=0&&text[i]!=pat[j]) j = lps[j] - 1;
            
            if(j==-1) j=0;
            
            if(text[i]==pat[j]) j++;
            // if(i>20) cout<<i<<": "<<text[i]<<", "<<j<<"\n";
            
            if(j==np) return i-np+1;
            
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