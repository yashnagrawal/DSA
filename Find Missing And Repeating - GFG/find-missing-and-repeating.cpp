//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, long long int n) {
        // code here
        
        long long int a, b;
        
        long long int sum = 0, square_sum = 0;
        long long int ideal_sum = (((n)*(n+1))/2ll), ideal_square_sum = (((n)*(n+1)*(2ll*n+1))/6ll);
        
        for(auto i: arr){
            sum+=(long long int)i;
            square_sum+=((long long int)i*(long long int)i);
        }
        
        long long int diff_of_nums = ideal_sum - sum;
        long long int sum_of_nums = (ideal_square_sum-square_sum)/diff_of_nums;
        
        a = (sum_of_nums + diff_of_nums)/2;
        b = (sum_of_nums - diff_of_nums)/2;
        
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