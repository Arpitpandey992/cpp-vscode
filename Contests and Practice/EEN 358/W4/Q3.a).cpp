#include <iostream>
using namespace std;

struct DQ {
    int st, ed;
    int *a, n;
    DQ(int sz = 1000) {  //Default max size=1000
        n = sz + 2;
        a = new int[n];
        st = 0;
        ed = 1;
    }
    bool underflow() {
        return (st + 1) % n == ed;
    }
    bool overflow() {
        return (ed + 1) % n == st;
    }
    void print() {
        if (underflow()) {
            cout << "Deque is empty\n";
            return;
        }
        cout << "Head = " << a[(st + 1) % n] << " "
             << "Tail = " << a[(((ed - 1) % n) + n) % n] << endl;
    }
    void addDQ_back(int x) {
        if (overflow()) {
            cout << "Adding " << x << " ... ";
            cout << "Deque is Full, Cannot add\n";
            return;
        }
        int ind = ed;
        a[ind] = x;
        ed = (ed + 1) % n;
        cout << "After Adding " << x << " at the back,\n";
        print();
    }
    void addDQ_Front(int x) {
        if (overflow()) {
            cout << "Adding " << x << " ... ";
            cout << "Deque is Full, Cannot add\n";
            return;
        }
        int ind = st;
        a[ind] = x;
        st = (((st - 1) % n) + n) % n;
        cout << "After Adding " << x << " at the Front,\n";
        print();
    }
    int removeDQ_front() {
        if (underflow()) {
            cout << "Deque is Empty\n";
            return -1;
        }
        int ind = (st + 1) % n;
        int t = a[ind];
        st = ind;
        cout << "After Removing " << t << " From Front,\n";
        print();
        return t;
    }
    int removeDQ_back() {
        if (underflow()) {
            cout << "Deque is Empty\n";
            return -1;
        }
        int ind = (((ed - 1) % n) + n) % n;
        int t = a[ind];
        ed = ind;
        cout << "After Removing " << t << " From Back,\n";
        print();
        return t;
    }
};

int main() {
    DQ dq(5);  //Initializing a queue of max size of 5
    dq.addDQ_back(4);
    dq.addDQ_Front(5);
    dq.addDQ_back(7);
    dq.addDQ_back(55);
    dq.addDQ_Front(1);
    dq.addDQ_Front(98);
    cout << endl;
    while (!dq.underflow()) {
        dq.removeDQ_back();
        if (dq.underflow()) break;
        dq.removeDQ_front();
    }
}