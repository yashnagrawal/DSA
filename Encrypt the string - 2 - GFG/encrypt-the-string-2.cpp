//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string dec_to_hex(int n){
        if(n==0) return "0";
        string ans = "";
        while(n>0){
            int digit = n%16;
            n/=16;
            if(digit<10) ans=to_string(digit)+ans;
            else ans=(char)('a'+(digit-10))+ans;
        }
        return ans;
    }
    string encryptString(string s) {
        int n = s.length();
        string ans = "";
        int i=0;
        
        while(i<n){
            int ctr = 1;
            char c = s[i++];
            while(i<n){
                if(c!=s[i]) break;
                else ctr++;
                i++;
            }
            ans=dec_to_hex(ctr)+c+ans;
            // cout<<i<<": "<<c<<", "<<ctr<<"\n";
        }
        
        // reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;

        Solution ob;
        cout<<ob.encryptString(S)<<endl;
    }
    return 0;
}
// } Driver Code Ends