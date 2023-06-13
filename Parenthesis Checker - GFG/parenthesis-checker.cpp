//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> s;
        
        for(auto ch: x){
            // cout<<ch<<"\n";
            if(s.empty()){
                if(ch=='['||ch=='{'||ch=='(') s.push(ch);
                else return false;
            }
            else{
                char top = s.top();
                if(ch=='['||ch=='{'||ch=='(') s.push(ch);
                else if((top=='['&&ch==']')||(top=='{'&&ch=='}')||(top=='('&&ch==')')) s.pop();
                else return false;
            }
        }
        
        return s.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends