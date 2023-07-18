//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool density_sort(pair<double, Item> &d1, pair<double, Item> &d2){
        return d1.first>d2.first;
    }
    
    double fractionalKnapsack(int sack_wt, Item arr[], int n)
    {
        // Your code here
        vector<pair<double, Item>> sorted_by_density;
        
        double sack_cap = sack_wt;
        
        for(int i=0; i<n; i++){
            Item item = arr[i];
            double density = (double)item.value/(double)item.weight;
            sorted_by_density.push_back({density, item});
        }
        
        sort(sorted_by_density.begin(), sorted_by_density.end(), density_sort);
        
        double max_value = 0;
        
        for(int i=0; i<n; i++){
            if(sack_cap==0) break;
            Item item = sorted_by_density[i].second;
            
            double wt = item.weight;
            double val = item.value;
            
            double fraction = 1;
            
            if(wt>sack_cap) fraction = sack_cap/wt;
            
            max_value += val*fraction;
            sack_cap -= wt*fraction;
            
            // cout<<wt<<", "<<val<<": "<<max_value<<", "<<sack_cap<<"\n";
        }
        
        return max_value;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends