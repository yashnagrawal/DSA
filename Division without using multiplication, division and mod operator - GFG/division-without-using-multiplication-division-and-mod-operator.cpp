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
        long long quotient = 0;
        
        bool neg = 0;
        
        if((dividend<0&&divisor>0)||(dividend>0&&divisor<0)) neg = 1;
        
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        for(int i=31; i>=0; i--){
            long long int num = divisor<<i;
            
            if(num<=dividend){
                dividend-=num;
                quotient = (quotient|(1<<i));
                // cout<<(1<<i)<<": "<<quotient<<"\n";
            }
        }
        
        if(neg) quotient = -quotient;
        
        return quotient;
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