//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> span(n, 1);
       vector<int> prev_greater(n, -1);
       stack<int> stk;
       
       for(int i=0; i<n; i++){
           while(!stk.empty()&&price[i]>=price[stk.top()]) stk.pop();
           
           if(!stk.empty()) prev_greater[i] = stk.top();
           stk.push(i);
       }
       
       for(int i=0; i<n; i++){
           span[i]=i-prev_greater[i];
       }
       
       return span;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends