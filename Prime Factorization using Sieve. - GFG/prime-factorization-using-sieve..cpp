//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int n) {

        // Write your code here
        vector<int> primes;
        
        while(n&&n%2==0){
            primes.push_back(2);
            n/=2;
        } 
        
        for(int i=3; i<=n; i+=2){
            while(n&&n%i==0){
                primes.push_back(i);
                n/=i;
            }
        }
        
        return primes;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends