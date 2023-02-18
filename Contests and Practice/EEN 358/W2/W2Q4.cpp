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
    cout << "\nLinked List is \n";
    while (a) {
        cout << a->val << "->";
        a = a->next;
    }
    cout << "\n\nCorresponding Addresses are: \n";
    while (b) {
        cout << b << "->";
        b = b->next;
    }
    cout << endl;
}
pair<node*, node*> search(node* a, int key) {
    node* pre = a;
    a = a->next;
    while (a) {
        if (a->val == key)
            return {pre, a};
        a = a->next;
        pre = pre->next;
    }
    return {NULL, NULL};
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
        cout << "\nEnter number to be searched : ";
        cin >> key;
        pair<node*, node*> temp2 = search(obj, key);
        if (temp2.first) {
            cout << "Present at Location " << temp2.second << endl;
            if (temp2.first == obj)
                cout << "The searched Element is at the first Position\n";
            else
                cout << "Previous element is " << temp2.first->val << " at Memory " << temp2.first << endl;
        } else
            cout << "Element Not Present\n";
    }
}
