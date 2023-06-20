//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int n = s.length();
        int ans = 0;
        
        
        for(int i=0; i<n; i++){
            vector<int> freq(26, 0);
            for(int j=i; j<n; j++){
                
                int ch = s[j] - 'a';
                
                freq[ch]++;
                int mini = INT_MAX;
                int maxi = 0;
                
                for(int k=0; k<26; k++){
                    if(freq[k]!=0){
                        mini = min(mini, freq[k]);
                        maxi = max(maxi, freq[k]);
                    }
                }
                
                if(mini!=INT_MAX) ans += maxi - mini;
            }
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
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends