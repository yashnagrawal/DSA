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
    string preToInfixHelper(string pre_exp, int lo, int hi){
        string infix;
        if(lo==hi){
            infix = pre_exp[lo];
            return infix;
        }
        
        if(!isOperator(pre_exp[lo])) return "INVALID PREFIX\n"; 
        
        int ind = lo + 1;
        int operators = 0;
        int variables = 0;
        for(; ind<=hi; ind++){
            if(isOperator(pre_exp[ind])) operators++;
            else variables++;
            if(operators+1==variables) break;
        }
        if(operators+1!=variables||ind==hi) return "INVALID PREFIX\n";
        
        infix = "(" + preToInfixHelper(pre_exp, lo+1, ind)  + pre_exp[lo] + preToInfixHelper(pre_exp, ind+1, hi) + ")";
        return infix;
    }
    
    string preToInfix(string pre_exp) {
        // Write your code here
        int n = pre_exp.length();
        return preToInfixHelper(pre_exp, 0, n-1);
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
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends