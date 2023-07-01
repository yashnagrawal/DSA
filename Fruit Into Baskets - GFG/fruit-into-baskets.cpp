//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int n, vector<int> &fruits) {
        int ans = 0;
        int j = 0;
        
        unordered_map<int, int> fruit_freq;
        
        for(int i=0; i<n; i++){
            fruit_freq[fruits[i]]++;
            
            while(fruit_freq.size()>2){
                fruit_freq[fruits[j]]--;
                
                if(fruit_freq[fruits[j]]==0) fruit_freq.erase(fruits[j]);
                
                j++;
            }
            
            ans = max(ans, i-j+1);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends