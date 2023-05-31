//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        // code here
        sort(arr, arr+n);
        vector<long long int> ans;
        
        for(int i=n-1; i>0; i=i-2){
            if(arr[i]!=arr[i-1]){
                ans.push_back(arr[i]);
                break;
            }
        }
        
        for(int i=0; i<n-1; i=i+2){
            if(arr[i]!=arr[i+1]){
                ans.push_back(arr[i]);
                break;
            }
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
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends