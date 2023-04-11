//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& a) {
        // Code here
        sort(a.begin(), a.end());
        vector<int> lds(n, 1); 
        vector<int> predecessor(n, -1);
        vector<int> ans;
        
        int ansi = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(a[i]%a[j]==0&&lds[i]<lds[j]+1){
                    lds[i]=lds[j]+1;
                    predecessor[i]=j;
                }
            }
            if(lds[ansi]<lds[i]) ansi = i;
        }
        
        while(ansi!=-1){
            ans.push_back(a[ansi]);
            ansi=predecessor[ansi];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends