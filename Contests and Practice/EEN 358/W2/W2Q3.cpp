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
    node* b = a->next;
    a = a->next;
    cout << "Linked List is \n";
    while (a) {
        cout << a->val << "->";
        a = a->next;
    }
    cout << "\nCorresponding Addresses are: \n";
    while (b) {
        cout << b << "->";
        b = b->next;
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
    int key, m;
    cout << "How many elements to search? ";
    cin >> m;
    while (m--) {
        cout << "Enter number to be searched : ";
        cin >> key;
        node* temp2 = search(obj, key);
        if (temp2)
            cout << "Present at Location " << temp2 << endl;
        else
            cout << "Element Not Present\n";
    }
}
