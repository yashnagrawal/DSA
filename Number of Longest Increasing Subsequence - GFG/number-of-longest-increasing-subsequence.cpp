//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&a) {
        // Code here
        
        int lis_length=0;
        int ans = 0;
        
        vector<int> nlis(n, 1);
        
        vector<int> lis(n, 1);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(a[i]>a[j]){
                    if(lis[i]<lis[j]+1){
                        lis[i]=lis[j]+1;
                        nlis[i]=nlis[j];
                    }
                    else if(lis[i]==lis[j]+1){
                        nlis[i]+=nlis[j];
                    }
                }
            }
            
            lis_length=max(lis_length, lis[i]);
        }
        
        for(int i=0; i<n; i++){
            if(lis[i]==lis_length) ans+=nlis[i];
        }
        
        // for(auto i: lis) cout<<i<<" ";
        // cout<<"\n";
        
        // for(auto j: nlis) cout<<j<<" ";
        // cout<<"\n";
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends