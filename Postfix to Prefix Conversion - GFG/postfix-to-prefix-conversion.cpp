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
    
    string postToPreHelper(string post_exp, int lo, int hi){
        string prefix;
        if(lo==hi){
            prefix = post_exp[lo];
            return prefix;
        }
        
        if(!isOperator(post_exp[hi])) return "INVALID PREFIX";
        
        int ind = hi-1;
        int operators = 0;
        int variables = 0;
        
        for(; ind>=lo; ind--){
            if(isOperator(post_exp[ind])) operators++;
            else variables++;
            if(variables==operators+1) break;
        }
        
        if(ind==lo||variables!=operators+1) return "INVALID PREFIX";
        
        prefix = post_exp[hi] + postToPreHelper(post_exp, lo, ind-1) + postToPreHelper(post_exp, ind, hi-1);
        
        return prefix;
    }
    string postToPre(string post_exp) {
        // Write your code here
        int n = post_exp.length();
        return postToPreHelper(post_exp, 0, n-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends