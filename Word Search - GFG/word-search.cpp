//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> addx = {-1, 1, 0, 0};
    vector<int> addy = {0, 0, -1, 1};
    
    bool inRange(int x, int y, int n, int m){
        return x>=0&&y>=0&&x<n&&y<m;
    }
    
    bool dfs(int ind, int x, int y, int nw, string word, vector<vector<char>> &board, int n, int m){
        if(ind==nw) return true;
        if(board[x][y]!=word[ind]) return false;
        
        char temp = board[x][y];
        board[x][y] = '0';
        
        for(int i=0; i<4; i++){
            int nx = x + addx[i];
            int ny = y + addy[i];
            
            if(inRange(nx, ny, n, m)&&dfs(ind+1, nx, ny, nw, word, board, n, m)) return true;
        }
        
        board[x][y] = temp;
        
        return false;
        
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        
        int n = board.size();
        int m = board[0].size();
        int nw = word.length();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dfs(0, i, j, nw, word, board, n, m)) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends