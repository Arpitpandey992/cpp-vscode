#include <iostream>
using namespace std;
struct node {
    int data;
    struct node* next;
    struct node* prev;
    node(int x) {
        data = x;
        next = prev = NULL;
    }
} * head, *tail;
void print() {
    if (!head) {
        cout << "List is Currently Empty!\n";
        return;
    }
    node* a = head;
    cout << "Linked List is \n";
    while (a) {
        if (!a->next) {
            cout << a->data;
            break;
        }
        cout << a->data << "<->";
        a = a->next;
    }
    cout << endl;
}
void push_front(int data) {
    if (!head) {
        head = tail = new node(data);
        return;
    }
    head->prev = new node(data);
    head->prev->next = head;
    head = head->prev;
}
void push_back(int data) {
    if (!head) {
        head = tail = new node(data);
        return;
    }
    tail->next = new node(data);
    tail->next->prev = tail;
    tail = tail->next;
}
void insertAfterNode(node* Node, int data) {
    if (!Node) {
        cout << "Invalid input\n";
        return;
    }
    node* temp = Node->next;
    Node->next = new node(data);
    Node->next->prev = Node;
    temp->prev = Node->next;
    Node->next->next = temp;
    if (Node == tail) tail = Node->next;
}
void insertBeforeNode(node* Node, int data) {
    if (!Node) {
        cout << "Invalid input\n";
        return;
    }
    node* temp = Node->prev;
    Node->prev = new node(data);
    Node->prev->next = Node;
    temp->next = Node->prev;
    Node->prev->prev = temp;
    if (Node == head) head = Node->prev;
}
node* get(int i) {  //Get the ith node from front
    node* a = head;
    i--;
    while (i--) {
        if (!a) {
            cout << "The element requested is out of bounds\n";
            return NULL;
        }
        a = a->next;
    }
    return a;
}
node* getFromBack(int i) {  //Get the ith node from back
    node* a = tail;
    i--;
    while (i--) {
        if (!a) {
            cout << "The element requested is out of bounds\n";
            return NULL;
        }
        a = a->prev;
    }
    return a;
}
void insert_DLL() {
    head = tail = NULL;
    print();
    push_back(5);
    cout << "After Pushing back 5\n";
    print();
    push_front(4);
    cout << "After Pushing front 4\n";
    print();
    push_back(43);
    cout << "After Pushing back 43\n";
    print();
    cout << "After inserting 20 after 2nd node in the list\n";
    insertAfterNode(get(2), 20);
    print();
    cout << "After inserting 15 before 3rd node from the end in the list\n";
    insertBeforeNode(getFromBack(3), 15);
    print();
}
int main() {
    insert_DLL();
}