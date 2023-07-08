//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> currency_list = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        vector<int> coins;
        int sum = N;
        
        int nc = 10;
        
        for(int i=nc-1; i>=0; i--){
            while(sum>=currency_list[i]){
                coins.push_back(currency_list[i]);
                sum-=currency_list[i];
            }
            
            if(sum==0) break;
        }
        
        return coins;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends