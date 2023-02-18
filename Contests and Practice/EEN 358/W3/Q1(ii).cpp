#include <bits/stdc++.h>
using namespace std;

struct node {
    int v;
    node *next, *prev;
    node(int x) {
        v = x;
        next = prev = NULL;
    }
};
struct Stack {
    int sz;
    node* tp;
    Stack() {
        sz = 0;
        tp = NULL;
    }
    // core functions
    int top() {
        return tp->v;
    }
    void push(int v) {
        cout << "Trying to push " << v << " into the stack...";
        if (overflow()) {
            cout << "OVERFLOW!!!, Couldn't Push\n";
            return;
        }
        node* y = new node(v);
        if (tp) tp->next = y;
        y->prev = tp;
        tp = y;
        sz++;
        cout << "Success\n";
    }
    int pop() {
        if (underflow()) {
            cout << "\nUNDERFLOW!!! Couldn't Pop\n";
            return -1;
        }
        int y = top();
        tp = tp->prev;
        sz--;
        if (!tp)
            return y;
        if (tp->next)
            delete tp->next;
        tp->next = NULL;
        return y;
    }
    // misc functions
    bool underflow() {
        return sz == 0;
    }
    bool overflow() {
        node* temp = new node(-1);  // temp node to check if heap is full or not
        if (temp) return false;
        return true;  //memory couldn't be allocated.
    }
};

int main() {
    Stack st;
    st.push(4);
    st.push(5);
    st.push(3);
    st.push(7);
    st.push(1);
    st.push(9);
    st.push(10);
    cout << "Popping elements...\n";
    while (!st.underflow()) {
        cout << st.pop() << " ";
    }
    st.pop();  //Popping after emptying, should result in underflow.
}