#include <iostream>
using namespace std;

struct node {
    int val;
    node* next;
    node(int val) {
        this->val = val;
        next = NULL;
    }
};

int josephus(int n, int k) {
    // n=number of persons standing, and
    //k -> every kth person is killed in one iteration
    k--;
    node* a = new node(1);
    node* t = a;
    for (int i = 2; i <= n; i++) {
        t->next = new node(i);
        t = t->next;
    }
    t->next = a;  //circular binding
    node* sec = a->next;
    int i = 1;
    while (sec != a) {
        if (i == k) {
            a->next = sec->next;
            a = a->next;
            sec = a->next;
            i = 1;
        } else {
            i++;
            a = a->next;
            sec = sec->next;
        }
    }
    cout << "n = " << n << " and k = " << k << " : Last person standing : " << a->val << endl;
}
int main() {
    josephus(2, 2);
    josephus(5, 3);
    josephus(6, 2);
    josephus(14, 7);
    josephus(34, 22);
    josephus(10223, 343);
}