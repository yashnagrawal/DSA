//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int subarraysWithAtMaxTarget(vector<int> &arr, int n, int target){
        int j = 0;
        int curr_sum = 0;
        int ans = 0;
        
        for(int i=0; i<n; i++){
            curr_sum +=arr[i];
            
            while(curr_sum>target){
                curr_sum-=arr[j];
                j++;
            }
            
            ans += (i-j+1);
        }
        
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& arr, int n, int target){
        // code here
        return subarraysWithAtMaxTarget(arr, n, target)-subarraysWithAtMaxTarget(arr, n, target-1);
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