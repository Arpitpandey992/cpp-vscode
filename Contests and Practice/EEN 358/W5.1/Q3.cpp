#include <iostream>
#include <string>
using namespace std;
struct tree {
    int val;
    tree *left, *right;
    tree(int x) {
        val = x;
        left = right = NULL;
    }
};
struct Node {
    tree* val;
    Node *next, *prev;
    Node(tree* root) {
        val = root;
        next = NULL;
        prev = NULL;
    }
};
class Stack {
    Node* topVal;

   public:
    Stack() {
        topVal = NULL;
    }
    void push(tree* x) {
        Node* t = new Node(x);
        if (topVal == NULL) {
            topVal = t;
            return;
        }
        topVal->next = t;
        t->prev = topVal;
        topVal = t;
    }
    void pop() {
        Node* t = topVal;
        topVal = topVal->prev;
        if (topVal != NULL) topVal->next = NULL;
        delete (t);
    }
    tree* top() {
        return topVal->val;
    }
    bool empty() {
        return (topVal == NULL);
    }
};
void PreOrderRecursive(tree* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    PreOrderRecursive(root->left);
    PreOrderRecursive(root->right);
}
void InOrderRecursive(tree* root) {
    if (root == NULL) return;
    InOrderRecursive(root->left);
    cout << root->val << " ";
    InOrderRecursive(root->right);
}
void PostOrderRecursive(tree* root) {
    if (root == NULL) return;
    PostOrderRecursive(root->left);
    PostOrderRecursive(root->right);
    cout << root->val << " ";
}
void PreOrderIterative(tree* root) {
    if (root == NULL) return;
    Stack buffer;
    buffer.push(root);
    while (buffer.empty() == false) {
        tree* temp = buffer.top();
        buffer.pop();
        cout << temp->val << " ";
        if (temp->right) buffer.push(temp->right);
        if (temp->left) buffer.push(temp->left);
    }
}
void InOrderIterative(tree* root) {
    if (root == NULL) return;
    Stack buffer;
    tree* curr = root;
    while (curr != NULL || buffer.empty() == false) {
        while (curr != NULL) {
            buffer.push(curr);
            curr = curr->left;
        }
        curr = buffer.top();
        buffer.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
}
void PostOrderIterative(tree* root) {
    if (root == NULL) return;
    Stack buffer1, buffer2;
    buffer1.push(root);
    tree* temp;
    while (!buffer1.empty()) {
        temp = buffer1.top();
        buffer1.pop();
        buffer2.push(temp);
        if (temp->left) buffer1.push(temp->left);
        if (temp->right) buffer1.push(temp->right);
    }
    while (!buffer2.empty()) {
        temp = buffer2.top();
        buffer2.pop();
        cout << temp->val << " ";
    }
}
tree* insert_bst(tree* root, int x) {
    if (root == NULL) {
        tree* newNode = new tree(x);
        return newNode;
    }
    if (x < root->val)
        root->left = insert_bst(root->left, x);
    else if (x > root->val)
        root->right = insert_bst(root->right, x);
    return root;
}
tree* delete_bst(tree* root, int x) {
    if (root == NULL) return NULL;
    if (x == root->val) {
        if (root->left == NULL && root->right == NULL)
            return NULL;
        else if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;
        else {
            tree* temp = root->right;
            while (temp->left != NULL) temp = temp->left;
            root->val = temp->val;
            root->right = delete_bst(root->right, temp->val);
        }
    } else if (x < root->val)
        root->left = delete_bst(root->left, x);
    else if (x > root->val)
        root->right = delete_bst(root->right, x);
    return root;
}
int main() {
    tree* root = NULL;
    cout << "Choose among the following operations (Not case sensitive)\n"
         << "Insert x (where x = integer)\n"
         << "Delete x (where x = integer)\n"
         << "inorder\n"
         << "Preorder\n"
         << "Postorder\n"
         << "Exit (to exit the program)\n\n";
    while (1) {
        string s;
        cin >> s;
        for (auto& x : s)
            x = tolower(x);

        if (s == "insert") {
            int x;
            cin >> x;
            root = insert_bst(root, x);
        } else if (s == "delete") {
            int x;
            cin >> x;
            root = delete_bst(root, x);
        } else if (s == "preorder") {
            cout << "PreOrder traversal with recursion : ";
            PreOrderRecursive(root);
            cout << endl;
            cout << "PreOrder traversal without recursion : ";
            PreOrderIterative(root);
            cout << endl;
        } else if (s == "inorder") {
            cout << "InOrder traversal with recursion : ";
            InOrderRecursive(root);
            cout << endl;
            cout << "InOrder traversal without recursion : ";
            InOrderIterative(root);
            cout << endl;
        } else if (s == "postorder") {
            cout << "PostOrder traversal with recursion : ";
            PostOrderRecursive(root);
            cout << endl;
            cout << "PostOrder traversal without recursion : ";
            PostOrderIterative(root);
            cout << endl;
        } else if (s == "exit") {
            cout << "Closing Program....\n";
            return 0;
        } else
            cout << "Invalid entry, Try again\n";
    }
}