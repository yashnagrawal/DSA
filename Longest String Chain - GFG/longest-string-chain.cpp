//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    static bool sortByLength(string w1, string w2){
        return w1.length()<w2.length();
    }
    bool isPredecessor(string wa, string wb){
        if(wa.length()+1!=wb.length()) return false;
        
        int i = 0;
        int add = 0;
        
        while(i<wa.length()&&i+add<wb.length()){
            if(wa[i]==wb[i+add]) i++;
            else add++;
            if(add>1) return false;
        }
        
        return true;
    }
    int longestChain(int n, vector<string>& words) {
        // Code here
        int ans = 0;
        
        vector<int> dp(n, 1);
        
        sort(words.begin(), words.end(), sortByLength);
        
        // for(auto i: words) cout<<i<<" ";
        // cout<<"\n";
        
        for(int i=0; i<n; i++){
            // cout<<i<<": ";
            for(int j=0; j<i; j++){
                // cout<<isPredecessor(words[j], words[i])<<" ";
                if(isPredecessor(words[j], words[i])) dp[i]=max(dp[i], 1+dp[j]); 
            }
            // cout<<"\n";
            ans=max(ans, dp[i]);
        }
        
        // for(auto j: dp) cout<<j<<" ";
        // cout<<"\n";
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends