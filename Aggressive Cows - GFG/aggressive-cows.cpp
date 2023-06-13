//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int number_of_cows_with_distance(int n, vector<int> &stalls, int distance){
        int num_of_cows = 1;
        
        int j = 0;
        
        for(int i=1; i<n; i++){
            if(abs(stalls[i]-stalls[j])>=distance){
                j=i;
                num_of_cows++;
            }
        }
        
        // cout<<distance<<": "<<num_of_cows<<"\n";
        
        return num_of_cows;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        int min_distance = 0;
        sort(stalls.begin(), stalls.end());
        
        int lo = 0;
        int hi = stalls[n-1]-stalls[0];
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            // cout<<lo<<", "<<hi<<" - ";
            
            if(number_of_cows_with_distance(n, stalls, mid)<k) hi = mid;
            else lo = mid + 1;
        }
        
        return lo-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends