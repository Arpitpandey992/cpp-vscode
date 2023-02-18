#include <iostream>
using namespace std;

struct Queue {
    int st, ed;
    int *a, n;
    Queue(int sz = 1000) {  //Default max size=1000
        sz = max(sz, 2);
        n = sz + 1;
        a = new int[sz + 1];
        st = 0;
        ed = 1;
    }
    bool underflow() {
        return (st + 1) % n == ed;
    }
    bool overflow() {
        return st == ed;
    }
    void print() {
        if (underflow()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Head = " << a[st] << " "
             << "Tail = " << a[(((ed - 2) % n) + n) % n] << endl;
    }
    void add(int x) {
        if (overflow()) {
            cout << "Adding " << x << " ... ";
            cout << "Queue is Full, Cannot add\n";
            return;
        }
        int ind = (((ed - 1) % n) + n) % n;
        a[ind] = x;
        ed = (ed + 1) % n;
        cout << "After Adding " << x << " at the back,\n";
        print();
    }
    int remove() {
        if (underflow()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        int t = a[st];
        st = (st + 1) % n;
        cout << "After Removing " << t << " From Front,\n";
        print();
        return t;
    }
};

int main() {
    Queue q(4);  //Initializing a queue of max size of 4
    q.add(4);
    q.add(5);
    q.add(7);
    q.add(55);
    q.add(1);
    q.add(98);
    while (!q.underflow()) {
        cout << q.remove() << endl;
    }
}