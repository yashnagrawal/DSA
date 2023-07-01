//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string str) {
        // Code here
        int n = str.length();
        int j = 0;

        int freq_a = 0;
        int freq_b = 0;
        int freq_c = 0;
        
        int diff = 0;
        
        for(int i=0; i<n; i++){
            char ch = str[i];
            
            if(ch=='a') freq_a++;
            if(ch=='b') freq_b++;
            if(ch=='c') freq_c++;
            
            while(freq_a&&freq_b&&freq_c){
                char chj = str[j++];
                
                if(chj=='a') freq_a--;
                if(chj=='b') freq_b--;
                if(chj=='c') freq_c--;
                
            }
            
            diff += (i-j+1);
        }
        
        
        
        return n*(n+1)/2-diff;
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
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends