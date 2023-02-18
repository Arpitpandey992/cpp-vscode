#include <iostream>
using namespace std;

struct node {
    int val;
    node *next, *prev;
    node(int t) {
        val = t;
        next = prev = NULL;
    }
};

struct DQ {
    node *head, *tail;
    DQ() {
        head = new node(0);
        tail = new node(0);
        head->next = tail;
        tail->prev = head;
    }
    bool underflow() {
        return head->next == tail;
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
            cout << "Deque is empty\n";
            return;
        }
        cout << "Head = " << head->next->val << " "
             << "Tail = " << tail->prev->val << endl;
    }
    void addDQ_back(int x) {
        if (overflow()) {
            cout << "Adding " << x << " ... ";
            cout << "Deque is Full, Cannot add\n";
            return;
        }
        node *temp = new node(x);
        node *Pnode = tail->prev;
        Pnode->next = temp;
        temp->prev = Pnode;
        temp->next = tail;
        tail->prev = temp;
        cout << "After Adding " << x << " at the back,\n";
        print();
    }
    void addDQ_front(int x) {
        if (overflow()) {
            cout << "Adding " << x << " ... ";
            cout << "Deque is Full, Cannot add\n";
            return;
        }
        node *temp = new node(x);
        node *Nnode = head->next;
        Nnode->prev = temp;
        temp->next = Nnode;
        temp->prev = head;
        head->next = temp;
        cout << "After Adding " << x << " at the Front,\n";
        print();
    }
    int removeDQ_front() {
        if (underflow()) {
            cout << "Deque is Empty\n";
            return -1;
        }
        node *temp = head->next;
        head->next = temp->next;
        head->next->prev = head;
        int t = temp->val;
        delete temp;
        cout << "After Removing " << t << " From Front,\n";
        print();
        return t;
    }
    int removeDQ_back() {
        if (underflow()) {
            cout << "Deque is Empty\n";
            return -1;
        }
        node *temp = tail->prev;
        tail->prev = temp->prev;
        tail->prev->next = tail;
        int t = temp->val;
        delete temp;
        cout << "After Removing " << t << " From Back,\n";
        print();
        return t;
    }
};

int main() {
    DQ dq;  //Initializing a queue of max size of 5
    dq.addDQ_back(4);
    dq.addDQ_front(5);
    dq.addDQ_back(7);
    dq.addDQ_back(55);
    dq.addDQ_front(1);
    dq.addDQ_front(98);
    cout << endl;
    while (!dq.underflow()) {
        dq.removeDQ_back();
        if (dq.underflow()) break;
        dq.removeDQ_front();
    }
}