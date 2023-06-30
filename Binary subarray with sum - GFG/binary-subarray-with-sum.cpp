//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int numberOfSubarrays(vector<int>& arr, int n, int target){
        // code here
        unordered_map<int, int> prefix_count;
        int prefix = 0;
        int ans = 0;
        
        prefix_count[prefix] = 1;
        
        for(int i=0; i<n; i++){
            prefix+=arr[i];
            
            prefix_count[prefix]++;
            
            // cout<<i<<": "<<prefix<<", "<<prefix_count[prefix]<<"\n";
            
            ans+=prefix_count[prefix-target];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends