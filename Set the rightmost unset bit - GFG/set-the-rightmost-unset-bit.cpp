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
        
        int first_set=1;
        
        while(first_set<=n){
            if((first_set&n)==0) break;
            first_set = first_set<<1;
        }
        
        if(first_set>=n) return n;
        
        return first_set|n;
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