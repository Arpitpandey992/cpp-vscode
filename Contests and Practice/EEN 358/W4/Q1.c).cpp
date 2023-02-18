#include <iostream>
using namespace std;

bool underflow(int n) {
    return n == 0;
}
bool overflow(int siz, int n) {
    return n == siz;
}
void print(int q[], int& size, int& head, int& tail) {
    if (underflow(size)) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Head = " << q[head] << " "
         << "Tail = " << q[tail - 1] << endl;
}
void add(int q[], int& size, int& head, int& tail, int maxsize, int link[], int x) {
    if (overflow(size, maxsize)) {
        cout << "Adding " << x << " ... ";
        cout << "Queue is Full, Cannot add\n";
        return;
    }
    size++;
    q[tail] = x;
    tail = link[tail];
    cout << "After Adding " << x << " at the back,\n";
    print(q, size, head, tail);
}

int remove(int q[], int& size, int& head, int& tail, int link[]) {
    if (underflow(size)) {
        cout << "Queue is Empty\n";
        return -1;
    }
    size--;
    int t = q[head];
    head = link[head];
    cout << "After Removing " << t << " From Front,\n";
    print(q, size, head, tail);
    return t;
}

int main() {
    int mx = 5;  // max size of queue = 5
    int q[mx];
    int link[mx];
    for (int i = 0; i < mx; i++) {
        link[i] = i + 1;
    }
    int head = 0, tail = 0;
    int size = 0;
    add(q, size, head, tail, mx, link, 4);
    add(q, size, head, tail, mx, link, 5);
    add(q, size, head, tail, mx, link, 7);
    add(q, size, head, tail, mx, link, 55);
    add(q, size, head, tail, mx, link, 1);
    add(q, size, head, tail, mx, link, 98);
    while (!underflow(size)) {
        cout << remove(q, size, head, tail, link) << endl;
    }
}
