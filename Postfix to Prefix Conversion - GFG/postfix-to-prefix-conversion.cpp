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
    
    string postToPreHelper(string post_exp, int &ind){
        string prefix = "";
        if(ind<0) return prefix;
        
        if(!isOperator(post_exp[ind])){
            prefix = post_exp[ind--];
            return prefix;
        }
        
        char op = post_exp[ind--];
        string right = postToPreHelper(post_exp, ind);
        string left = postToPreHelper(post_exp, ind);
        
        prefix = op + left + right;
        
        return prefix;
    }
    string postToPre(string post_exp) {
        // Write your code here
        int n = post_exp.length();
        int ind = n-1;
        return postToPreHelper(post_exp, ind);
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