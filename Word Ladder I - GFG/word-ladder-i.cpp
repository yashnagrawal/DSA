//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int diff(string &a, string &b){
        if(a.length()!=b.length()) return INT_MAX;
        
        int n = a.length();
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            if(a[i]!=b[i]) cnt++;
        }
        
        return cnt;
    }

    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        queue<string> q;
        int n = wordList.size();
        
        unordered_map<string, bool> visited;
        
        q.push(startWord);
        visited[startWord] = 1;
        int ans = 0;
        
        while(!q.empty()){
            int nc = q.size();
            ans++;
            
            while(nc--){
                string front = q.front();
                
                if(front==targetWord) return ans;
                q.pop();
                
                for(int i=0; i<n; i++){
                    if(!visited[wordList[i]]&&diff(front, wordList[i])==1){
                        q.push(wordList[i]);
                        visited[wordList[i]] = 1;
                    }
                }
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends