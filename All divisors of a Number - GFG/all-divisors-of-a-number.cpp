//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        
        stack<int> stk;
        
        for(int i=1; i*i<=n; i++){
            if((n%i)==0){
                cout<<i<<" ";
                int pair = n/i;
                
                if(pair!=i) stk.push(pair);
            }
        }
        
        while(!stk.empty()){
            cout<<stk.top()<<" ";
            stk.pop();
        }
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends