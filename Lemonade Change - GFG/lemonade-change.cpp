//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int n, vector<int> &bills) {
        // code here
        vector<int> freq(3, 0);
        
        for(int i=0; i<n; i++){
            int change = bills[i] - 5;
            
            if(bills[i]==5) freq[0]++;
            if(bills[i]==10) freq[1]++;
            if(bills[i]==20) freq[2]++;
            
            while(change>=20&&freq[2]){
                freq[2]--;
                change-=20;
            }
                
            while(change>=10&&freq[1]){
                freq[1]--;
                change-=10;
            }
                
            while(change>=5&&freq[0]){
                freq[0]--;
                change-=5;
            }
            
            if(change!=0) return false;
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends