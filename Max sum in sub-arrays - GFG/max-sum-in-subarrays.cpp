//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends


class Solution{
    public:
        long long pairWithMaxSum(long long arr[], long long n)
    {
        // Your code goes here
        long long ans = INT_MIN;
        stack<long long> s;
        
        vector<long long> next_smallest_ind(n, INT_MIN), prev_smallest_ind(n, INT_MIN);
        
        for(int i=n-1; i>=0; i--){
            while((!s.empty())&&(arr[i]<arr[s.top()])) s.pop();
            
            if(!s.empty()) next_smallest_ind[i]=s.top();
            s.push(i);
        }
        
        while(!s.empty()) s.pop();
        
        for(int i=0; i<n; i++){
            while((!s.empty())&&(arr[i]<arr[s.top()])) s.pop();
            
            if(!s.empty()) prev_smallest_ind[i]=s.top();
            s.push(i);
        }
        
        // for(auto i: prev_smallest_ind){
        //     if(i!=INT_MIN) cout<<arr[i]<<" ";
        //     else cout<<"na ";
        // }
        // cout<<"\n";
        
        // for(auto i: next_smallest_ind){
        //     if(i!=INT_MIN) cout<<arr[i]<<" ";
        //     else cout<<"na ";
        // }
        // cout<<"\n";
        
        for(int i=0; i<n; i++){
            long long min1 = INT_MIN;
            if(next_smallest_ind[i]!=INT_MIN) min1 = max(min1, arr[next_smallest_ind[i]]);
            if(prev_smallest_ind[i]!=INT_MIN) min1 = max(min1, arr[prev_smallest_ind[i]]);
            long long min2 = arr[i];
            
            ans=max(ans, min1+min2);
        }
        
        return ans;
    }
};



//{ Driver Code Starts.
int main() 
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
	    for(ll i=0;i<n;i++)
		    cin>>a[i];
		Solution ob;
	    cout<<ob.pairWithMaxSum(a,n)<<endl;
	}
	return 0;
}


// } Driver Code Ends