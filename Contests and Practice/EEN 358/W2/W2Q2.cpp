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
int siz(node* a) {
    int n = 0;
    while (a) {
        a = a->next;
        n++;
    }
    return n;
}
node* merge(node* a, node* b, int n, int m) {
    node* c = new node(0);
    node* head = c;
    while (n || m) {
        if (n && m) {
            if (a->val <= b->val) {
                c->next = a;
                a = a->next;
                n--;
            } else {
                c->next = b;
                b = b->next;
                m--;
            }
        } else if (n) {
            c->next = a;
            a = a->next;
            n--;
        } else {
            c->next = b;
            b = b->next;
            m--;
        }
        c = c->next;
    }
    c->next = NULL;
    return head->next;
}
node* msort(node* a, int n) {
    if (n == 1) return a;
    node *left = a, *rig = a;
    int i = n / 2;
    while (i--) rig = rig->next;
    left = msort(left, n / 2);
    rig = msort(rig, n - (n / 2));
    return merge(left, rig, n / 2, n - (n / 2));
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
    cout << "Before Sorting\n";
    print(obj);
    obj->next = msort(obj->next, n);
    cout << "After Sorting\n";
    print(obj);
}
