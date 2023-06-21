//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}


// } Driver Code Ends
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code here
        // return the head of intersection list
        unordered_map<int, bool> isPresentInLL2;
        Node* intersection_head = NULL;
        Node* intersection_last = NULL;
        
        Node* curr_node = head2;
        
        while(curr_node!=NULL){
            isPresentInLL2[curr_node->data]=1;
            curr_node = curr_node->next;
        }
        
        curr_node = head1;
        
        while(curr_node!=NULL){
            int data = curr_node->data;
            curr_node = curr_node->next;
            
            if(isPresentInLL2.find(data)==isPresentInLL2.end()) continue;
            
            if(intersection_last==NULL){
                intersection_last = new Node(data);
                intersection_head = intersection_last;
            }
            else{
                intersection_last->next = new Node(data);
                intersection_last = intersection_last->next;
            }
            
        }
        
        return intersection_head;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    
	    cin>> n;
	    Node* head1 = inputList(n);
	    
	    cin>>m;
	    Node* head2 = inputList(m);
	    Solution obj;
	    Node* result = obj.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends