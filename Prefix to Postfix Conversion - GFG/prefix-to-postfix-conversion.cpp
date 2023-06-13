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
    
    string preToPostHelper(string &pre_exp, int &ind, int n){
        string postfix = "";
        if(ind==n) return postfix;
        if(!isOperator(pre_exp[ind])){
            postfix = pre_exp[ind++];
            return postfix;
        }
        
        char op = pre_exp[ind++];
        
        string left = preToPostHelper(pre_exp, ind, n);
        string right = preToPostHelper(pre_exp, ind, n);
        
        postfix = left + right + op;
        
        return postfix;
    }
    
    string preToPost(string pre_exp) {
        int n = pre_exp.length();
        int ind = 0;
        return preToPostHelper(pre_exp, ind, n);
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