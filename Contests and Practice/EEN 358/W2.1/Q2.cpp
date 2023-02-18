#include <iostream>
using namespace std;
struct node {
    int val;
    node* next;
    node(int x) {
        val = x;
        next = NULL;
    }
};
node* merge(node* a, node* b) {
    node* c = new node(-2000000000);
    node* head = c;
    while (a && b) {
        if (a->val <= b->val) {
            c->next = a;
            c = c->next;
            a = a->next;
        } else {
            c->next = b;
            c = c->next;
            b = b->next;
        }
    }
    while (a) {
        c->next = a;
        c = c->next;
        a = a->next;
    }
    while (b) {
        c->next = b;
        c = c->next;
        b = b->next;
    }
    c->next = NULL;
    return head->next;
}

void print(node* a) {
    while (a) {
        cout << a->val << "->";
        a = a->next;
    }
}
node* input() {
    cout << "Enter the size of the list : ";
    int n;
    cin >> n;
    node* a = new node(-1);
    node* head = a;
    cout << "Enter " << n << " elements in sorted fashion (Ascending)\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a->next = new node(x);
        a = a->next;
    }
    return head->next;
}
int main() {
    cout << "Enter List 1\n";
    node* a = input();
    cout << "Enter List 2\n";
    node* b = input();
    node* c = merge(a, b);
    cout << "The Merged List is : \n";
    print(c);
}