//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
#define ll long long
class Solution{
public:
    vector<ll> dp;
    ll mod = 1000000007;
    ll moudular_pow(ll n, ll pow){
        if(pow==0) return 1;
        
        ll ans = moudular_pow(n, pow/2);
        ans=(ans*ans)%mod;
        if(pow%2) ans=(ans*n)%mod;
        
        return ans;
    }
    ll modular_inv(ll n){
        moudular_pow(n, mod-2);
    }
    
    ll c(ll n, ll r){
        ll num = dp[n];
        
        ll den = (dp[r]*dp[n-r])%mod;
        
        return (num*modular_inv(den))%mod;
    }
    
    vector<ll> nthRowOfPascalTriangle(ll n) {
        // code here
        dp.push_back(1);
        for(int i=1; i<n; i++) dp.push_back((dp[i-1]*i)%mod);
        
        vector<ll> ans(n, 1ll);
        
        for(int j=0; j<n; j++){
            ans[j]=c(n-1, j);
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends