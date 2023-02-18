#include <iostream>
using namespace std;

struct node {
    int val, priority;
    node *next;
    node(int val, int p) {
        this->val = val;
        priority = p;
        next = NULL;
    }
};

struct PQ {
    node *head;
    PQ() {
        head = NULL;
    }
    void addPQ(int d, int p) {
        node *n = new node(d, p);
        node *cur = head;
        if (head == NULL) {
            head = n;
        } else if (p < cur->priority) {
            n->next = head;
            head = n;
        } else {
            while (cur->next != NULL && p >= cur->next->priority)
                cur = cur->next;
            n->next = cur->next;
            cur->next = n;
        }
        cout << "Added " << d << " With Priority " << p << endl;
    }
    int removePQ() {
        if (head != NULL) {
            int r = (head)->val;
            node *n = head;
            if ((head)->next)
                head = (head)->next;
            else
                head = NULL;
            n = NULL;
            return r;
        }
        cout << "Priority Queue is Empty, Cannot Remove \n";
        return -1000000000;  //PQ is empty
    }
};
int main() {
    PQ pq;
    pq.addPQ(1, 1);
    pq.addPQ(21, 3);
    pq.addPQ(14, 7);
    pq.addPQ(35, 2);
    pq.addPQ(0, 5);
    pq.addPQ(23, 4);
    pq.addPQ(12, 9);
    int n;
    // Removing from smallest Priority to highest
    while (n = pq.removePQ(), n != -1000000000) {
        cout << "Removed from Priority Queue -> " << n << endl;
    }
}
