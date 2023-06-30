//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        //code here
        
        int neg = ((dividend>0)^(divisor>0))?(-1):(1);
        
        dividend=abs(dividend);
        divisor=abs(divisor);
        
        long long quotient = 0;
        
        long long mul = divisor<<31;
        long long t = 1;
        long long pow_of_2 = t<<31;
        
        for(int i=31; i>=0&&dividend; i--){
            if(mul<=dividend){
                dividend-=mul;
                
                quotient = quotient|pow_of_2;
            }
            
            // cout<<i<<": "<<quotient<<", "<<mul<<", "<<pow_of_2<<"\n";
            
            mul = mul>>1;
            pow_of_2 = pow_of_2>>1;
        }
        
        return neg*quotient;
        
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends