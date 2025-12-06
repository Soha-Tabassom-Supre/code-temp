#include <bits/stdc++.h>
using namespace std;
#define ll long long
class node{
  public:  
    int data;       
    node* next;     
    node(int val)   
    {
        data = val;
        next = NULL; 
    }
};

class lists{
    node* head;     
    node* tail;     
    public:
    lists()
    {
        head = tail = NULL; 
    }
    
     void push_back(int val)
    {
        node* newnode = new node(val);
        if(head == NULL) head = tail = newnode; // empty list case
        else{
            tail->next = newnode;    // link old tail to newnode
            tail = newnode;          // update tail
        }
    }

    void reverse()
    {
      node*curr=head;
      node*prev=NULL;
      node*next=NULL;
       tail=curr;
      while(curr !=NULL)
      {
         next=curr->next;
         curr->next=prev;
         prev=curr;
         curr=next;
      }
      prev=head;

    }

    void middlels()
    {
        node*temp=head;
        int count=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
      
    }
};
int main()
{

}