//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isOperator(char ch){
        return ch=='+'||ch=='-'||ch=='*'||ch=='/';
    }
    
    string preToPostHelper(string pre_exp, int lo, int hi){
        string postfix;
        if(lo==hi){
            postfix = pre_exp[lo];
            return postfix;
        }
        
        if(!isOperator(pre_exp[lo])) return "INVALID PREFIX";
        
        int ind = lo + 1;
        int operators = 0;
        int variables = 0;
        
        for(; ind<=hi; ind++){
            if(isOperator(pre_exp[ind])) operators++;
            else variables++;
            if(variables==operators+1) break;
        }
        
        if(ind==hi||variables!=operators+1) return "INVALID PREFIX";
        
        postfix = preToPostHelper(pre_exp, lo+1, ind) + preToPostHelper(pre_exp, ind+1, hi) + pre_exp[lo];
        
        return postfix;
    }
    
    string preToPost(string pre_exp) {
        int n = pre_exp.length();
        return preToPostHelper(pre_exp, 0, n-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends