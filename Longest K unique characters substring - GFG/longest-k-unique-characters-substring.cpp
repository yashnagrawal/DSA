//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string str, int k) {
    // your code here
        int n = str.length();
        
        int j = 0;
        int ans = -1;
        
        unordered_map<char, int> freq;
        
        for(int i=0; i<n; i++){
            char ch = str[i];
            freq[ch]++;
            
            while(freq.size()>k){
                freq[str[j]]--;
                
                if(freq[str[j]]==0) freq.erase(str[j]);
                j++;
            }
            if(freq.size()==k) ans = max(ans, i-j+1);
            
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
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends