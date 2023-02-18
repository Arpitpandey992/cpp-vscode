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
node* create(int x) {
    return new node(x);
}
void print(node* a) {
    a = a->next;
    cout << "Linked List is \n";
    while (a) {
        cout << a->val << "->";
        a = a->next;
    }
    cout << endl;
}

void ins_sorted(node* a, int val) {
    node* sec = a->next;
    while (sec) {
        if (sec->val >= val) {
            a->next = new node(val);
            a->next->next = sec;
            return;
        }
        sec = sec->next;
        a = a->next;
    }
    a->next = new node(val);
}
int main() {
    node* obj = create(-1);
    int n;
    cout << "Enter The number of Elements - ";
    cin >> n;
    node* temp = obj;
    cout << "Enter " << n << " Elements in a sorted fashion\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        temp->next = create(x);
        temp = temp->next;
    }
    print(obj);
    int val, m;
    cout << "How many elements to Insert? ";
    cin >> m;
    while (m--) {
        cout << "\nEnter which number to insert : ";
        cin >> val;
        ins_sorted(obj, val);
        cout << "\nAfter Inserting, The list is :\n";
        print(obj);
    }
}
