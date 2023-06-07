//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        
        int a=0, b=0;
        
        int xor_of_arr = 0;
        
        for(auto i: arr) xor_of_arr^=i;
        
        for(int i=1; i<=n; i++) xor_of_arr^=i;
        
        int right_most_bit_num = xor_of_arr&~(xor_of_arr-1);
        
        // cout<<xor_of_arr<<" "<<right_most_bit_num<<"\n";
        
        for(int i=1; i<=n; i++){
            if(i&right_most_bit_num) a^=i;
            else b^=i;
        }
        
        for(auto i: arr){
            if(i&right_most_bit_num) a^=i;
            else b^=i;
        }
        
        int b_freq = 0;
        
        for(auto i: arr){
            if(i==b) b_freq++;
        }
        
        if(b_freq==0) swap(a, b);
        
        return {b, a};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends