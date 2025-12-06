#include <bits/stdc++.h>
using namespace std;
#define ll long long
class node{
    public:
    int data;
    node*prev;
    node*next;
    node(int val)
    {
        data=val;
        prev=next=NULL;
    }
};
class doublels{
   
    node*head;
    node*tail;
    public:
    doublels()
    {
        head=tail=NULL;
    }

   void  push_front(int val)
   {
     node*newnode=new node(val);
     if(head==NULL)
     {
        head=tail=newnode;
     }
     else 
     {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
     }
   }
   
   void push_back(int val)
   {
     node*newnode=new node(val);
      if(head==NULL)
     {
        head=tail=newnode;
     }
     else 
     {
         node*temp=head;
       
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
     }
   }

    void push_beforevalue(int val,int inside)//see this function
    {
       node*newnode= new node(val);
       node*temp=head;
       while(temp!=NULL && temp->data!=inside)
       {
        temp=temp->next;
       }
       if(temp==NULL)return;
       if(temp==head)
       {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        
       }else{
           newnode->prev=temp->prev;
           newnode->next=temp;
            temp->prev->next = newnode;
           temp->prev=newnode;
       }

    }

    void pop_back()
    {
        node*temp=head;
        if(tail=NULL)return;
        if(head==tail){
            delete tail;
            head=tail=NULL;
        }
        else{
           node*temp=tail;
           tail=tail->prev;
           tail->next=NULL;
        }

    }

    void pop_front()
    {
        if(head==NULL)return;
        if(head==tail){
            delete head;
            head=tail=NULL;
        }
        else{
            node*temp=head;
            head=head->next;
            head->prev=NULL;
            delete temp;
        }
    }

    void delete_all_occurrences(int val)//see this code
{
    node* temp = head;

    while(temp != NULL)
    {
        node* nextNode = temp->next; // save next before delete

        if(temp->data == val)
        {
            if(temp == head && temp == tail)
            {
                delete temp;
                head = tail = NULL;
            }
            else if(temp == head)
            {
                head = head->next;
                head->prev = NULL;
                delete temp;
            }
            else if(temp == tail)
            {
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
        }
        temp = nextNode; // continue safely
    }
}
   void print()
   {
     node*temp=head;
     while(temp!=NULL)
     {
        cout<<temp->data<<" ";
        temp=temp->next;
     }
     cout<<endl;
   }

   void backward_traversal()
   {
      node*temp=tail;
      int count=0;
      while(temp!=NULL)
      {
        cout<<temp->data<<" ";
        count++;
        temp=temp->prev;
      }
      cout<<endl;
      cout<<count<<endl;
   }

   void search(int val)
   {
     node*temp=head;
     int index=0;
     while(temp!=NULL)
     {
        if(temp->data==val)
        {
          cout<<"values position is "<<index+1<<endl;
        }
        index++;
        temp=temp->next;
     }
   }
};

int main()
{
    doublels ls;
    ls.push_front(10);
     ls.push_front(10);
      ls.push_front(10);
      ls.push_back(30);
      ls.push_back(50);
      ls.push_back(70);
      ls.push_beforevalue(40,50);
      ls.print();
      ls.backward_traversal();
      ls.search(50);
     
    return 0;
}
