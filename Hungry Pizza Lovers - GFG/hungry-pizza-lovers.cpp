//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> permute(vector<vector<int>> &arr, int n);


int main() {
    
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> arr(n);
        
        for(int i=0;i<n;i++)
        {
            int a, b;
            cin>> a>> b;
            arr[i].push_back(a);
            arr[i].push_back(b);
        }
        
        vector<int> ans;
        ans = permute(arr, n);
        for(int i=0;i<n;i++)
            cout << ans[i] << "\n";
        
    }
    
	return 0;
}
// } Driver Code Ends


vector<int> permute(vector<vector<int>> &a, int n)
{
    
    // Complete the function
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> ans;
    
    for(int i=0; i<n; i++){
        pq.push({a[i][0]+a[i][1], i+1});
    }
    
    while(!pq.empty()){
        int top = pq.top().second;
        pq.pop();
        
        ans.push_back(top);
    }
    
    return ans;
}