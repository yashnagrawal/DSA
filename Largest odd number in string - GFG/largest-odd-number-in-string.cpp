//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string s) {
        // your code here
        int n = s.length();
        string curr_num = "";
        string ans = "";
        
        for(int i=0; i<n; i++){
            int num = s[i]-'0';
            
            curr_num += s[i];
            if(num%2) ans = curr_num;
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
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends