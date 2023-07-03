//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> addx = {-1, 1, 0, 0};
    vector<int> addy = {0, 0, -1, 1};
    
    bool inRange(int i, int j, int n, int m){
        return (i>=0)&&(j>=0)&&(i<n)&&(j<m);
    }
    
    void dfs(int i, int j, vector<vector<int>> &flooded_image, int n, int m, int newColor, int floodColor){
        flooded_image[i][j] = newColor;
        
        for(int k=0; k<4; k++){
            int ni = i + addx[k];
            int nj = j + addy[k];
            
            if(inRange(ni, nj, n, m)&&(flooded_image[ni][nj]==floodColor)) dfs(ni, nj, flooded_image, n, m, newColor, floodColor);
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>> flooded_image = image;
        
        int floodColor = image[sr][sc];
        
        if(floodColor!=newColor) dfs(sr, sc, flooded_image, n, m, newColor, floodColor);
        
        return flooded_image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends