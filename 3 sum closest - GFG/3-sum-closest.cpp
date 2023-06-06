//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int a[], int n, int x)
    {
        // code here
        
        sort(a, a+n);
        int closest_sum = INT_MAX;
        
        for(int i=0; i<n; i++){
            int st = 0;
            int ed = n-1;
            
            int triplet_sum = INT_MAX;
            
            while(st<i&&i<ed){
                int curr_sum = a[st]+a[i]+a[ed];
                if(curr_sum==x){
                    return x;
                }
                if(curr_sum>x){
                    if(abs(curr_sum-x)<=abs(triplet_sum-x)) triplet_sum = curr_sum;
                    ed--;
                }
                else{
                    if(abs(curr_sum-x)<abs(triplet_sum-x)) triplet_sum = curr_sum;
                    st++;
                }
            }
            
            if(abs(triplet_sum-x)<abs(closest_sum-x)) closest_sum = triplet_sum;
            else if(abs(triplet_sum-x)==abs(closest_sum-x)&&triplet_sum>closest_sum) closest_sum = triplet_sum;
        }
        
        return closest_sum;
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
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends