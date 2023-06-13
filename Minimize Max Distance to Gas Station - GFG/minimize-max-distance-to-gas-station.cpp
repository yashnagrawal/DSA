//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int extra_stations_required(double max_distance, vector<int> &stations, int n){
        if(max_distance == 0.0000) return 0;
        int extra_stations = 0;
        
        for(int i=1; i<n; i++){
            double distance = stations[i]-stations[i-1];
            
            extra_stations+=ceil(distance/max_distance)-1;

        }
        
        return extra_stations;
    }
    
    double findSmallestMaxDist(vector<int> &stations, int k){
      // Code here
      int n = stations.size();
      double lo = 0.0;
      double hi = stations[n-1]-stations[0];
      
      double prec = 1e-6;
      
      while(lo+prec<=hi){
          double mid = lo + (hi-lo)/2.0;

          if(extra_stations_required(mid, stations, n)<=k) hi = mid;
          else lo = mid;
      }
      
      return hi;
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends