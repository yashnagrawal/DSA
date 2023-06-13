//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int find_max_bouquets_possible(vector<int> &bloomDay, int k, int n, int day){
        int max_bouquets_possible = 0;
        int last_blossom_ind = 0;
        for(int i=0; i<n; i++){
            if(bloomDay[i]>day){
                max_bouquets_possible+=((i-last_blossom_ind)/k);
                last_blossom_ind=i+1;
            }
        }
        
        if(bloomDay[n-1]<=day) max_bouquets_possible+=((n-last_blossom_ind)/k);
        
        return max_bouquets_possible;
    }
  
    int solve(int m, int k, vector<int> &bloomDay){
          // Code here
          int n = bloomDay.size();
          if(m*k>n) return -1;
          
          int hi = INT_MIN;
          int lo = 0;
          
          for(auto day: bloomDay) hi = max(hi, day);
          
          while(lo<hi){
              int day = lo + (hi-lo)/2;
              
              if(find_max_bouquets_possible(bloomDay, k, n, day)>=m) hi = day;
              else lo = day + 1;
          }
          
          if(find_max_bouquets_possible(bloomDay, k, n, lo)==m) return lo;
          return -1;
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