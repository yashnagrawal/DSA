//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet{
    public:
    vector<int> parent;
    vector<int> size;
    
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 0);
        
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    
    int findParent(int num){
        if(size[num]==0) return -1;
        
        if(parent[num]==num) return num;
        
        return parent[num] = findParent(parent[num]);
    }
    
    int unionWithConsequtive(int num){
        size[num] = 1;
        
        if(num&&size[num-1]>0){
            int parent1 = findParent(num);
            int parent2 = findParent(num-1);
            
            int size1 = size[parent1];
            int size2 = size[parent2];
            
            if(parent1!=parent2){
                if(size1<size2){
                    parent[parent1] = parent2;
                    size[parent2]+=size1;
                }
                else{
                    parent[parent2] = parent1;
                    size[parent1]+=size2;
                }
            }
        }
        
        if(size[num+1]>0){
            int parent1 = findParent(num);
            int parent2 = findParent(num+1);
            
            int size1 = size[parent1];
            int size2 = size[parent2];
            
            if(parent1!=parent2){
                if(size1<size2){
                    parent[parent1] = parent2;
                    size[parent2]+=size1;
                }
                else{
                    parent[parent2] = parent1;
                    size[parent1]+=size2;
                    
                }
            }
        }
        
        
        
        return size[findParent(num)];
    }
    
    void printDisjointSet(int st, int ed){
        for(int i=st; i<=ed; i++) cout<<i<<" ";
        
        cout<<"\n";
        
        for(int i=st; i<=ed; i++) cout<<parent[i]<<" ";
        
        cout<<"\n";
        
        for(int i=st; i<=ed; i++) cout<<size[i]<<"  ";
        
        cout<<"\n";
    }
};

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      DisjointSet ds(100000);
      
      int ans = 1;
      
      for(int i=0; i<n; i++){
          
          ans = max(ans, ds.unionWithConsequtive(arr[i]));
          
        //   cout<<arr[i]<<": \n";
          
        //   ds.printDisjointSet(41, 47);
      }
      
      return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends