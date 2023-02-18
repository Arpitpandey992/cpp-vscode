#include <iostream>
using namespace std;
const int MAXP = 8, MAXN = 500;
//Maximum priority allowed = 8
//Maximum size of individual lists = 500
int q[MAXP + 1][MAXN + 1];

bool underflow(int size) {
    return size == 0;
}

bool overflow(int size) {
    return size == MAXN;
}

void addPQ(int front[], int rear[], int size[], int x, int p) {
    if (p > MAXP) {
        cout << "Cannot add " << x << " With Priority " << p << " Because " << endl;
        cout << "-> Element's Priority is higher than the maximum Priority allowed (" << MAXP << ")\n";
        return;
    }
    if (overflow(size[p])) {
        cout << "Cannot add " << x << " With Priority " << p << " Because " << endl;
        cout << "-> The list of priority = " << p << " is Full\n";
        return;
    }
    size[p]++;
    q[p][rear[p]++] = x;
    rear[p] %= MAXN;
    cout << "Added " << x << " With Priority " << p << endl;
}

int removePQ(int front[], int rear[], int size[]) {
    for (int i = 0; i <= MAXP; i++)
        if (!underflow(size[i])) {
            size[i]--;
            int v = q[i][front[i]];
            front[i] = (front[i] + 1) % MAXN;
            return v;
        }
    cout << "Priority Queue is empty" << endl;
    return -1000000000;
}

int main() {
    int rear[MAXP + 1] = {0}, front[MAXP + 1] = {0}, size[MAXP + 1] = {0};

    addPQ(front, rear, size, 1, 1);
    addPQ(front, rear, size, 21, 3);
    addPQ(front, rear, size, 14, 7);
    addPQ(front, rear, size, 35, 2);
    addPQ(front, rear, size, 0, 5);
    addPQ(front, rear, size, 23, 4);
    addPQ(front, rear, size, 12, 9);
    int v;
    // Removing from smallest Priority to highest
    while (v = removePQ(front, rear, size), v != -1000000000) {
        cout << "Removed from Priority Queue -> " << v << endl;
    }
}
