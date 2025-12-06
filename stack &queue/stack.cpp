#include <bits/stdc++.h>
using namespace std;
#define ll long long
//LIFO
// Stack using vector
class stacks {
    vector<int> v;
public:
    void push(int val) { v.push_back(val); }
    void pop() { if (!v.empty()) v.pop_back(); }
    int top() { return v.back(); }
    bool empty() { return v.empty(); }
};

// Stack using list
class lists {
    list<int> ls;
public:
    void push(int val) { ls.push_front(val); }
    void pop() { if (!ls.empty()) ls.pop_front(); }
    int top() { return ls.front(); }
    bool empty() { return ls.empty(); }
};

// Stack using STL
class stls {
public:
    void demo() {
        stack<int> stt;
        stt.push(10);
        stt.push(20);
        stt.push(30);

        cout << "Top element: " << stt.top() << endl; // 30
        stt.pop();
        cout << "Top after pop: " << stt.top() << endl; // 20
    }
};

class arr{
    public:
    int arr[100];
    int top=-1;
    void push(int val)
    {
        if(top<100)
      arr[++top]=val;
    }

    void pop()
    {
        if(top>=0)top--;
    }

    void top()
    {
        if(top>=0)
        {
            cout<<arr[top];
            top--;

        }
    }
    bool isempty()
    {
        if(top==-1)return true;
        else return false;
    }

    bool isful()
    {
        return top==99;
    }


    void reverse_array( )
    {
        
    }
};

int main() {
    // Vector-based stack
    stacks st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl; // 30
    st.pop();
    cout << "Top after pop: " << st.top() << endl; // 20

    // List-based stack
    lists ls;
    ls.push(100);
    ls.push(200);
    cout << "List stack top: " << ls.top() << endl; // 200
    ls.pop();
    cout << "List stack after pop: " << ls.top() << endl; // 100

    // STL stack demo
    stls obj;
    obj.demo();

    return 0;
}