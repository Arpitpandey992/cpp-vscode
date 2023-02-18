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

bool ins_k(node* a, int key, int val) {
    node* sec = a->next;
    int i = 0;
    while (sec) {
        if (i == key) {
            a->next = new node(val);
            a->next->next = sec;
            return true;
        }
        i++;
        sec = sec->next;
        a = a->next;
    }
    if (i == key) {
        a->next = new node(val);
        a->next->next = sec;
        return true;
    }
    return false;
}
int main() {
    node* obj = create(-1);
    int n;
    cout << "Enter The number of Elements - ";
    cin >> n;
    node* temp = obj;
    cout << "Enter " << n << " Elements\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        temp->next = create(x);
        temp = temp->next;
    }
    print(obj);
    int val, key, m;
    cout << "How many elements to Insert? ";
    cin >> m;
    while (m--) {
        cout << "\nEnter which number to insert, and at what position (0 - " << n << ") : ";
        cin >> val >> key;
        bool flag = ins_k(obj, key, val);
        if (flag) {
            n++;
            cout << "\nAfter Inserting, The list is :\n";
            print(obj);
        } else
            cout << "Invalid input\n";
    }
}
