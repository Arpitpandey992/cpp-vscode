#include <bits/stdc++.h>
using namespace std;

struct Stack {
    int *st, *flink, *blink, top, n;  //forward link and backward link
    Stack(int n) {
        n += 2;  //first and last position are reserved for checking overflow and underflow
        this->n = n;
        st = new int[n];
        flink = new int[n];
        blink = new int[n];
        top = 0;
        for (int i = 0; i < n - 1; i++) {
            flink[i] = i + 1;
            blink[i + 1] = i;
        }
    }
    bool overflow() {
        return (flink[top] == n - 1);
    }
    bool underflow() {
        return (top == 0);
    }
    void push(int v) {
        cout << "Trying to push " << v << " into the stack...";
        if (overflow()) {
            cout << "OVERFLOW!!!, Couldn't Push\n";
            return;
        }
        top = flink[top];
        st[top] = v;
        cout << "Success\n";
    }
    int pop() {
        if (underflow()) {
            cout << "\nUNDERFLOW!!! Couldn't Pop\n";
            return -1;
        }
        int t = st[top];
        top = blink[top];
        return t;
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
    st.push(10); //Pushing after filling 6 elements, should result in an overflow
    cout << "Popping elements...\n";
    while (!st.underflow()) {
        cout << st.pop() << " ";
    }
    st.pop();  //Popping after emptying, should result in underflow.
}
