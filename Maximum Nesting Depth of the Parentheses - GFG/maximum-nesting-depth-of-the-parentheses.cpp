//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string str) {
        // code here
        int curr_opens = 0;
        int ans = 0;
        
        for(auto ch: str){
            if(ch=='(') curr_opens++;
            else if(ch==')') curr_opens--;
            
            ans = max(ans, curr_opens);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends