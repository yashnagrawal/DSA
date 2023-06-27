//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<string> combinations;
    unordered_map<int, list<char>> mp;
    
    void recr(string str, int ind, int a[], int n){
        if(ind==n) combinations.push_back(str);
        
        for(auto i: mp[a[ind]]){
            string new_str = str + i;
            
            recr(new_str, ind+1, a, n);
        }
        
        return;
    }
    
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int n)
    {
        //Your code here
        for(char ch='a'; ch<='z'; ch++){
            if(ch<='r'){
                int diff = ch-'a';
                mp[2+diff/3].push_back(ch);
            }
            else if(ch=='s') mp[7].push_back(ch);
            else if(ch<='v') mp[8].push_back(ch);
            else mp[9].push_back(ch);
        }
        
        recr("", 0, a, n);
        
        return combinations;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends