//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isBouquetPossible(vector<int> &bloomDay, int m, int k, int n, int day){
        int max_bouquets_possible = 0;
        
        int st = 0;
        int ed = 0;
        
        while(ed<n){
            if(bloomDay[ed]<=day) ed++;
            else{
                max_bouquets_possible+=((ed-st)/k);
                st = ++ed;
            }
        }
        
        if(bloomDay[n-1]<=day) max_bouquets_possible+=((ed-st)/k);
        
        // cout<<day<<": "<<max_bouquets_possible<<"\n";
        
        return max_bouquets_possible>=m;
    }
  
    int solve(int m, int k, vector<int> &bloomDay){
          // Code here
          int n = bloomDay.size();
          if(m*k>n) return -1;
          int lo = 0;
          int hi = INT_MIN;
          
          for(auto i: bloomDay) hi = max(hi, i);
          
          while(lo<hi){
              int mid = lo + (hi-lo)/2;
              
              if(isBouquetPossible(bloomDay, m, k, n, mid)) hi = mid;
              else lo = mid + 1;
          }
          
          return (isBouquetPossible(bloomDay, m, k, n, lo))?lo:-1;
      
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends