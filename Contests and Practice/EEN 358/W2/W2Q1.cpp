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
void modify(node* a, int x) {  //adds x to all values
    a = a->next;
    while (a) {
        a->val += x;
        a = a->next;
    }
}
int count(node* a) {
    int n = 0;
    while (a) {
        n++;
        a = a->next;
    }
    return n - 1;
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
    cout << "Size of Linked List is: " << count(obj) << endl;
    cout << "After adding 4 to every element in the list\n";
    modify(obj, 4);  //Adding 4 to every element in the list
    print(obj);
}
