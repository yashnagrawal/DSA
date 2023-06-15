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
    
    string postToInfix(string post_exp) {
        // Write your code here
        int n = post_exp.length();
        stack<string> stk;
        
        for(auto ch: post_exp){
            string ch_str = string(1, ch);
            if(!isOperator(ch)) stk.push(ch_str);
            else{
                string right = stk.top();
                stk.pop();
                string left = stk.top();
                stk.pop();
                stk.push("("+left+ch_str+right+")");
            }
        }
        
        return stk.top();
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
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends