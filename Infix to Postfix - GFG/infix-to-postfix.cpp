//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    bool isOperator(char ch){
        return ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^';
    }
    
    int operatorPercedence(char ch){
        if(ch=='+'||ch=='-') return 1;
        if(ch=='*'||ch=='/') return 2;
        if(ch=='^') return 3;
        return -1;
    }
    
    string infixToPostfix(string s) {
        // Your code here
        string postfix = "";
        
        stack<char> stk;
        
        for(auto ch: s){
            if(ch=='(') stk.push(ch);
            else if(isOperator(ch)){
                while(!stk.empty()&&operatorPercedence(stk.top())>=operatorPercedence(ch)){
                    postfix+=stk.top();
                    stk.pop();
                }
                
                stk.push(ch);
            }
            else if(ch==')'){
                while(!stk.empty()&&stk.top()!='('){
                    postfix+=stk.top();
                    stk.pop();
                }
                
                if(stk.empty()||stk.top()!='(') return "INVALID STRING\n";
                else stk.pop();
            }
            else{
                postfix+=ch;
            }
        }
        while(!stk.empty()){
            postfix+=stk.top();
            stk.pop();
        }
        
        return postfix;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends