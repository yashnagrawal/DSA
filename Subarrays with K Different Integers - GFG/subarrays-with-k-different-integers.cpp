//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int subarrayCountAtMaxK(vector<int> &arr, int n, int k){
        int ans = 0;
        
        vector<int> freq(n+1, 0);
        int distinct = 0;
        
        int j = 0;
        
        for(int i=0; i<n; i++){
            freq[arr[i]]++;
            
            if(freq[arr[i]]==1) distinct++;
            
            while(distinct>k){
                freq[arr[j]]--;
                
                
                if(freq[arr[j]]==0) distinct--;
                
                j++;
            }
            
            ans += (i-j+1);
        }
        
        return ans;
    }
    int subarrayCount(vector<int> &arr, int n, int k) {
        // code here
        
        return subarrayCountAtMaxK(arr, n, k) - subarrayCountAtMaxK(arr, n, k-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends