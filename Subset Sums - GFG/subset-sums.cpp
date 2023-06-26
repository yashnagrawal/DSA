//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> subsets;
    void recr(vector<int> &arr, int ind, int n, int sum){
        if(ind==n){
            subsets.push_back(sum);
            return;
        }
        
        recr(arr, ind+1, n, sum);
        recr(arr, ind+1, n, sum+arr[ind]);
        
        return;
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        sort(arr.begin(), arr.end());
        
        recr(arr, 0, n, 0);
        
        return subsets;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends