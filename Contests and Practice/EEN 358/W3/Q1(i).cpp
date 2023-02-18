#include <bits/stdc++.h>
using namespace std;

struct Stack {
    int *a, ind, mxsiz;
    Stack(int n) {
        mxsiz = n;
        a = new int[n];
        ind = 0;
    }
    bool underflow() {
        return ind == 0;
    }
    bool overflow() {
        return ind == mxsiz;
    }
    void push(int x) {
        cout << "Trying to push " << x << " into the stack...";
        if (overflow()) {
            cout << "OVERFLOW!!!, Couldn't Push\n";
            return;
        }
        a[ind++] = x;
        cout << "Success\n";
    }
    int pop() {
        if (underflow()) {
            cout << "\nUNDERFLOW!!! Couldn't Pop\n";
            return -1;
        }
        return a[--ind];
    }
};

int main() {
    Stack st(6);  //Max size of stack = 6
    st.push(4);
    st.push(5);
    st.push(3);
    st.push(7);
    st.push(1);
    st.push(9);
    st.push(10);  //Pushing after filling 6 elements, should result in an overflow
    cout << "Popping elements...\n";
    while (!st.underflow()) {
        cout << st.pop() << " ";
    }
    st.pop();  //Popping after emptying, should result in underflow.
}