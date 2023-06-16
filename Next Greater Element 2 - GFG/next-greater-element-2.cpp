//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int n, vector<int>& arr) {
        // code here
        
        vector<int> nge(n, -1);
        stack<int> stk;
        
        for(int i=n-1; i>=0; i--){
            while(!stk.empty()&&arr[i]>=stk.top()) stk.pop();
            stk.push(arr[i]);
        }
        
        for(int i=n-1; i>=0; i--){
            while(!stk.empty()&&arr[i]>=stk.top()) stk.pop();
            
            if(!stk.empty()) nge[i] = stk.top();
            stk.push(arr[i]);
        }
        
        return nge;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends