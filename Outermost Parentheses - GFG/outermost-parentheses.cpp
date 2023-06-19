//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        
        int n = s.length();
        string ans = "";
        string curr = "";
        
        int curr_opens = 0;
        
        for(auto ch: s){
            if(ch=='('){
                curr+="(";
                curr_opens++;
            }
            else{
                if(curr_opens>1){
                    curr+=")";
                    curr_opens--;
                }
                else{
                    string new_str = "";
                    
                    int len = curr.length();
                    
                    if(len>1) {
                        new_str = curr.substr(1, len-1);
                    }
                    
                    ans+=new_str;
                    curr_opens = 0;
                    curr="";
                }
            }
            // cout<<ch<<": "<<curr<<", "<<ans<<"\n";
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

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends