//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      
      set<int> s;
      
      for(int i=0; i<n; i++) s.insert(arr[i]);
      
      int curr = 1;
      int ans = 1;
      
      vector<int> a;
      
      for(auto i: s) a.push_back(i);
      
      int na = a.size();
      
      for(int i=1; i<na; i++){
          if(a[i]-a[i-1]==1){
              curr++;
              ans=max(ans, curr);
          }
          else{
              ans=max(ans, curr);
              curr=1;
          }
      }
      
      return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends