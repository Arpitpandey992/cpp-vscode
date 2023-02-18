#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
    node(int t) {
        val = t;
        next = NULL;
    }
};

struct Queue {
    node *head, *tail;
    int inf = -1e9;
    Queue() {
        head = tail = NULL;
    }
    bool underflow() {
        return head == NULL;
    }
    bool overflow() {
        node *temp = new node(5);  //checking if heap memory is full or not
        if (temp) {
            delete temp;
            return false;
        }
        return true;
    }
    void print() {
        if (underflow()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Head = " << head->val << " "
             << "Tail = " << tail->val << endl
             << endl;
    }
    void add(int x, bool Print = true) {
        if (overflow()) {
            cout << "Queue is Full\n";
            return;
        }
        if (underflow()) {
            node *temp = new node(x);
            head = tail = temp;
        } else {
            node *temp = new node(x);
            tail->next = temp;
            tail = tail->next;
        }
        if (Print) {
            cout << "After Adding " << x << " at the back,\n";
            print();
        }
    }
    int remove(bool Print = true) {
        if (underflow()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        node *temp = head;
        head = head->next;
        int t = temp->val;
        delete temp;
        cout << "After Removing " << t << " From Front,\n";
        if (Print) {
            print();
            return t;
        }
    }
};

int main() {
    Queue q;
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