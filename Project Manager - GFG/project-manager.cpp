//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


// } Driver Code Ends
class Solution{
    public:
    int minTime(vector<pair<int, int>> &dependency, int duration[], int n, int m) {
        // 	Write your code here
        vector<int> indegree(n, 0);
        vector<list<int>> al(n);
        vector<int> time(n, 0);
        vector<int> queue;
        int ans = 0;
        
        for(auto i: dependency){
            int from = i.first;
            int to = i.second;
            al[from].push_back(to);
            indegree[to]++;
        }
        
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                queue.push_back(i);
                time[i]=duration[i];
            }
        }
        
        while(!queue.empty()){
            int back = queue.back();
            queue.pop_back();
            ans=max(ans, time[back]);
            
            for(auto child: al[back]){
                indegree[child]--;
                time[child]=max(time[child], time[back]+duration[child]);
                if(indegree[child]==0){
                    queue.push_back(child);
                }
            }
        }
        
        for(auto i: indegree){
            if(i!=0){
                ans = -1;
                break;
            }
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m;
        int duration[n + 5];
        vector<pair<int, int>> dependency;
        for (int i = 0; i < n; i++) cin >> duration[i];
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            dependency.push_back({x, y});
        }
        Solution obj;
        cout << obj.minTime(dependency, duration, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends