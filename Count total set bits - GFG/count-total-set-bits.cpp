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
    
    int max2pow(int n){
        int ans = 0;
        while(n!=1){
            ans++;
            n/=2;
        }
        return ans;
    }
    
    int countSetBits(int n)
    {
        // Your logic here
        if(n<2) return n;
        int x = max2pow(n);
        int rem = n-(1<<(x));
        int set_bits_till_2_pow_x = (x)*(1<<(x-1));
        
        return set_bits_till_2_pow_x + rem + 1 + countSetBits(rem);
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