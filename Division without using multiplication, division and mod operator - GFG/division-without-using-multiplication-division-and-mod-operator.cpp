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
        
        for(int i=31; i>=0&&dividend>0; i--){
            long long mul = divisor<<i;
            
            if(mul<=dividend){
                dividend-=mul;
                
                quotient = quotient|(1<<i);
            }
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