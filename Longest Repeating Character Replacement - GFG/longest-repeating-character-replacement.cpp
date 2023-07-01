//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string str, int k) {
        // code here
        int n = str.length();
        int ans = 0;
        
        for(char ch='A'; ch<='Z'; ch++){
            int non_ch = 0;
            int j = 0;
            for(int i=0; i<n; i++){
                if(str[i]!=ch) non_ch++;
                
                while(non_ch>k){
                    if(str[j]!=ch) non_ch--;
                    j++;
                }
                
                ans = max(ans, i-j+1);
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
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends