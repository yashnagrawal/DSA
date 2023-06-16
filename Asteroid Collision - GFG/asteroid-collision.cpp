//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &asteroids) {
        // code here
        vector<int> left_asteroids;
        
        stack<int> stk;
        
        for(int i=0; i<n; i++){
            int val = asteroids[i];
            if(val>0){
                stk.push(val);
            }
            else{
                while(!stk.empty()&&stk.top()>0&&stk.top()<abs(val)) stk.pop();
                if(!stk.empty()&&stk.top()+val==0) stk.pop();
                else if(stk.empty()||stk.top()<0) stk.push(val);
            }
        }
        
        while(!stk.empty()){
            left_asteroids.push_back(stk.top());
            stk.pop();
        }
        
        reverse(left_asteroids.begin(), left_asteroids.end());
        
        return left_asteroids;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends