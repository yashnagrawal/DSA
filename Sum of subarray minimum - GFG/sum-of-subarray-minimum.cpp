//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int sumSubarrayMins(int n, vector<int> &arr) {
        // code here
        long long sum = 0;
        
        vector<int> prev_sml(n, -1);
        vector<int> next_sml(n, n);
        
        stack<int> stk;
        
        for(int i=0; i<n; i++){
            while(!stk.empty()&&arr[i]<=arr[stk.top()]) stk.pop();
            if(!stk.empty()) prev_sml[i]=stk.top();
            stk.push(i);
        }
        
        stk = stack<int> ();
        
        for(int i=n-1; i>=0; i--){
            while(!stk.empty()&&arr[i]<arr[stk.top()]) stk.pop();
            if(!stk.empty()) next_sml[i] = stk.top();
            stk.push(i);
        }
        
        for(int i=0; i<n; i++){
            int left = i - prev_sml[i];
            int right = next_sml[i] - i;
            sum += (arr[i]*left*right);
            sum%=1000000007;
        }
        
        return sum;
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
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends