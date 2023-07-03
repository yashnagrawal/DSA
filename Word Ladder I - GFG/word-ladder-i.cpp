//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        queue<string> q;
        int n = wordList.size();
        int m = wordList[0].length();
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        q.push(startWord);
        
        st.erase(startWord);
        int ans = 0;
        
        while(!q.empty()){
            int nc = q.size();
            ans++;
            
            while(nc--){
                string front_word = q.front();
                q.pop();
                
                if(front_word==targetWord) return ans;
                
                for(int i=0; i<m; i++){
                    
                    char org = front_word[i];
                    
                    for(char ch='a'; ch<='z'; ch++){
                        front_word[i] = ch;
                        
                        if(st.find(front_word)!=st.end()){
                            st.erase(front_word);
                            q.push(front_word);
                        }
                    }
                    
                    front_word[i] = org;
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