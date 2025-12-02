#include <bits/stdc++.h>
using namespace std;
#define ll long long

//for create new node
class node{
  public:  
    int data;       // stores the value
    node* next;     // pointer to next node
    node(int val)   // constructor
    {
        data = val;
        next = NULL; // initially no next node
    }
};

class lists{
    node* head;     
    node* tail;     
    public:
    lists()
    {
        head = tail = NULL; // empty list initially
    }

    
    void push_front(int ne)
    {
       node* newnode = new node(ne); // create new node
       if(head == NULL){             // if list empty
          head = tail = newnode;     // head and tail both point to newnode
       }
       else{
          newnode->next = head;      // link newnode to old head
          head = newnode;            // update head
       }
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

    // Remove from front
    void pop_front()
    {
        if(head == NULL) return;     // empty list → nothing to delete
        node* temp = head;           // store old head
        head = head->next;           // move head forward
        temp->next = NULL;           // disconnect old head
        delete temp;                 // free memory
    }

    
    void pop_back()
    {
      node* temp = head;
      // traverse until node before tail
      while(temp->next != tail)
      {
        temp = temp->next;
      }
      temp->next = NULL;             // disconnect last node
      delete tail;                   // free memory
      tail = temp;                   // update tail
    }

    // Insert at specific position
    void insert(int val,int pos){
      node* newnode = new node(val);
      node* temp = head;
      int currpos = 0;

      if(pos < 0) return;            // invalid position
      if(pos == 0){                  //insert at head
        push_front(val); 
        return;
      }

      // traverse until desired position
      while(currpos < pos-1 && temp != nullptr)
      {
        temp = temp->next;
        currpos++;
      }

      // link newnode into the list
      newnode->next = temp->next;    // connect newnode to next node
      temp->next = newnode;          // connect previous node to newnode
    }

    void reverse() {//iterative also has recursive
    node* prev = NULL;
    node* curr = head;
    node* next = NULL;
    tail = head; // after reversal, old head becomes tail

    while (curr != NULL) {
        next = curr->next;   // store next node
        curr->next = prev;   // reverse the link
        prev = curr;         // move prev forward
        curr = next;         // move curr forward
    }

    head = prev; // update head to new front
}


    void update(int pos, int newVal) {
    if (pos < 0) return; // invalid position
    node* temp = head;
    int currpos = 0;

    while (temp != nullptr && currpos < pos) {
        temp = temp->next;
        currpos++;
    }

    if (temp != nullptr) {
        temp->data = newVal; // update value
    } else {
        cout << "Invalid position\n";
    }
}


void replace(int x, int y) {
    node* temp = head;
    while (temp != nullptr) {
        if (temp->data == x) {
            temp->data = y; // replace value
        }
        temp = temp->next;
    }
}


    void display(){
       node* temp = head;
       while(temp != NULL)
       {
        cout << temp->data << " ";   // print current node data
        temp = temp->next;           // move forward
       }
       cout << endl;
    }
};

int main()
{
      lists ls; // create list object
      ls.push_front(19);  
      ls.push_front(23); 
      ls.push_front(45);  
      ls.push_back(34);   
      ls.display();      
      return 0;
}