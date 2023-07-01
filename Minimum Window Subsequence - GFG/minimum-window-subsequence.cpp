//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isSubsequence(string str1, string str2, int st, int ed, int n2){
        
        int j = 0;
        
        for(int i=st; j<n2&&i<=ed; i++){
            if(str1[i]==str2[j]) j++;
        }
        
        return j==n2;
    }
    
    string minWindow(string str1, string str2) {
        // Write your Code here
        
        int n1 = str1.length();
        int n2 = str2.length();
        
        int st = 0;
        int ed = n1-1;
        
        string ret = "";
        
        if(!isSubsequence(str1, str2, 0, n1-1, n2)) return ret;
        
        while(st<=ed){
            if(isSubsequence(str1, str2, st+1, ed, n2)) st++;
            else if(isSubsequence(str1, str2, st, ed-1, n2)) ed--;
            else break;
        }
        
        return str1.substr(st, ed-st+1);
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends