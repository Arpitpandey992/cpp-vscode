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

node* search(node* a, int key) {
    a = a->next;
    while (a) {
        if (a->val == key)
            return a;
        a = a->next;
    }
    return NULL;
}
bool ins_aft(node* a, int key, int val) {
    node* bef = search(a, key);
    if (bef) {
        node* temp = bef->next;
        bef->next = new node(val);
        bef->next->next = temp;
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
        cout << "\nEnter which number to insert, and after which number : ";
        cin >> val >> key;
        bool flag = ins_aft(obj, key, val);
        if (flag) {
            cout << "After Inserting, The list is :\n";
            print(obj);
        } else
            cout << "The given key is not present\n";
    }
}
