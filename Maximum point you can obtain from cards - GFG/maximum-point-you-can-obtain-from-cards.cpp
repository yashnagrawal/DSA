//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &cardPoints, int n, int k) {
        // code here
        int win_size = n-k;
        
        int sum = 0;
        int min_sum = INT_MAX;
        int tot_sum = 0;
        
        for(int i=0; i<n; i++){
            sum+=cardPoints[i];
            tot_sum+=cardPoints[i];
            
            
            if(i-win_size+1>=0){
                min_sum = min(min_sum, sum);
                sum-=cardPoints[i-win_size+1];
            }
        }
        
        if(win_size==0) min_sum = 0;
        
        return tot_sum - min_sum;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends