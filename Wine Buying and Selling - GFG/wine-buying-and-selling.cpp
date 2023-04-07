//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& a, int n){
      //Code here.
      vector<pair<int, int>> sell, buy;
      long long int ans = 0;
      
      for(int i=0; i<n; i++){
          if(a[i]>0) buy.push_back({i, a[i]});
          else if(a[i]<0) sell.push_back({i, -1*a[i]});
      }
      
      int is = 0, ib = 0;
      
      while(is+ib<n){
          if(buy[ib].second==sell[is].second){
              ans+=(abs(buy[ib].first-sell[is].first))*(buy[ib].second);
              ib++;
              is++;
          }
          else if(buy[ib].second<=sell[is].second){
              ans+=(abs(buy[ib].first-sell[is].first))*(buy[ib].second);
              sell[is].second-=buy[ib].second;
              ib++;
          }
          else{
              ans+=(abs(buy[ib].first-sell[is].first))*(sell[is].second);
              buy[ib].second-=sell[is].second;
              is++;
          }
      }
      
      return ans;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends