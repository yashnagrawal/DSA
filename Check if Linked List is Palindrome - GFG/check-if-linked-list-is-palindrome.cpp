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
    Node* reverseLL(Node* head){
        Node* last_node = NULL;
        Node* curr_node = head;
        
        while(curr_node!=NULL){
            Node* next_node = curr_node->next;
            
            curr_node->next = last_node;
            last_node = curr_node;
            
            curr_node = next_node;
        }
        
        if(last_node==NULL) return head;
        return last_node;
    }
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head==NULL||head->next==NULL) return true;
        
        Node* slow_node = head;
        Node* fast_node = head->next;
        
        while(fast_node!=NULL&&fast_node->next!=NULL){
            fast_node = fast_node->next->next;
            slow_node = slow_node->next;
        }
        
        slow_node->next = reverseLL(slow_node->next);
        
        Node* first_node = head;
        Node* second_node = slow_node->next;
        
        while(second_node!=NULL){
            if(first_node->data!=second_node->data) return false;
            first_node = first_node->next;
            second_node = second_node->next;
        }
        
        return true;
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