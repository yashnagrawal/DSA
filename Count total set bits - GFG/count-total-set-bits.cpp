//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    vector<int> max2Pow(int n){
        int num = 1;
        int pow = 0;
        
        while(num*2<=n){
            num*=2;
            pow++;
        }
        
        return {pow, num};
    }
    
    int countSetBits(int n)
    {
        
        if(n==0) return 0;
        
        vector<int> pows = max2Pow(n);
        
        int max_pow = pows[0];
        int max_num = pows[1];
        
        int rem = countSetBits(n-max_num);
        
        int ret = (n-max_num + 1) + rem + ((max_num/2)*max_pow);
        
        return ret;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends