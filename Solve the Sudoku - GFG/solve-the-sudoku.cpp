//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    
    
    bool isSudokuValid(int grid[N][N], int x, int y, int num){
        
        int sx = (x/3)*3;
        int sy = (y/3)*3;
        
        for(int t=0; t<N; t++){
            if(grid[t][y]==num) return false;
            if(grid[x][t]==num) return false;
            
            if(grid[sx+t/3][sy+t%3]==num) return false;
        }
        
        return true;
    }
    
    bool recr(int grid[N][N]){
        
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(grid[i][j]==0){
                    
                    for(int num=1; num<=N; num++){
                        
                        if(isSudokuValid(grid, i, j, num)){
                            
                            grid[i][j] = num;
                            if(recr(grid)) return true;
                            grid[i][j] = 0;
                            
                        }
                        
                    }
                    
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return recr(grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends