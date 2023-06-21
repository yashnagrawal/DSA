//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isSeqPalindrome(int num){
        int reverse = 0;
        
        int temp = num;
        
        while(temp>0){
            int digit = temp%10;
            temp/=10;
            
            reverse = reverse*10 + digit;
        }
        
        return num==reverse;
    }
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        int num = 0;
        
        Node* curr_node = head;
        
        while(curr_node!=NULL){
            int data = curr_node->data;
            
            num = num*10 + data;
            curr_node = curr_node->next;
        }
        
        return isSeqPalindrome(num);
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends