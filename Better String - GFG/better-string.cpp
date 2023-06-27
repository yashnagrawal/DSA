//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string betterString(string str1, string str2) {
        // code here
        
        int n1 = str1.size();
        int n2 = str2.size();
        
        vector<int> dp1(n1+1, 1);
        vector<int> dp2(n2+1, 1);
        
        unordered_map<char, int> last_occ1;
        unordered_map<char, int> last_occ2;
        
        for(int i=1; i<=n1; i++){
            dp1[i]=2*dp1[i-1];
            char ch = str1[i-1];
            
            if(last_occ1[ch]!=0){
                dp1[i]-=dp1[last_occ1[ch]-1];
            }
            last_occ1[ch] = i;
        }
        
        for(int i=1; i<=n2; i++){
            dp2[i] = 2*dp2[i-1];
            char ch = str2[i-1];
            
            if(last_occ2[ch]!=0){
                dp2[i]-=dp2[last_occ2[ch]-1];
            }
            last_occ2[ch] = i;
        }
        
        if(dp1[n1]>=dp2[n2]) return str1;
        return str2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends