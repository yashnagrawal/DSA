//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isDivisibleBy10(string bin) {
        // code here
        int ans = 0;
        
        for(auto i: bin){
            ans=((ans<<1)+(i-'0'))%10;
        }
        
        return (ans%10)==0;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string bin;
        cin >> bin;
        Solution ob;
        cout << ob.isDivisibleBy10(bin);
        cout << endl;
    }
}
// } Driver Code Ends