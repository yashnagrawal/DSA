//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    
    int celebrity(vector<vector<int> >& mat, int n) 
    {
        // code here 
        
        int st = 0;
        int ed = n-1;
        
        while(st<ed){
            if(mat[st][ed]==1) st++;
            else ed--;
        }
        
        int celebrity = st;
        
        for(int i=0; i<n; i++){
            if(i!=st&&mat[i][st]==0) celebrity = -1;
        }
        
        for(int j=0; j<n; j++){
            if(mat[st][j]==1) celebrity = -1;
        }
        
        return celebrity;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends