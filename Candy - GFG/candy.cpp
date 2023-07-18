//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // bool isMinima(int ind, vector<int> &ratings, int n){
    //     int left = (ind)?ratings[ind-1]:INT_MAX;
        
    //     int rating = ratings[ind];
        
    //     int right = (ind<n-1)?ratings[ind+1]:INT_MAX;
        
    //     return left>=rating&&right>=rating;
    // }
    
    int minCandy(int n, vector<int> &ratings) {
        // code here
        
        vector<int> candies(n, 1);
        
        for(int i=1; i<n; i++){
            if(ratings[i]>ratings[i-1]) candies[i] = max(candies[i], candies[i-1]+1);
        }
        
        for(int i=n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]) candies[i] = max(candies[i], candies[i+1]+1);
        }
        
        int total_candies = 0;
        
        for(auto cnt: candies) total_candies+=cnt;
        
        return total_candies;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends