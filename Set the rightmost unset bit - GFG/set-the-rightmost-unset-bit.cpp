//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setBit(int n)
    {
        // Write Your Code here
        int digit = 0;
        int ans = 0;
        
        int mod = n%2;
        while(n>0&&mod!=0){
            ans+=(mod<<(digit++));
            n/=2;
            mod = n%2;
        }
        
        if(n==0) return ans;
        
        mod = 1;
        
        while(n>0){
            ans+=(mod<<(digit++));
            n/=2;
            mod=n%2;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends