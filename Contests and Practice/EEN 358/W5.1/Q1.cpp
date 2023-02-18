#include <iostream>
#include <queue>
using namespace std;

struct tree {
    int val;
    tree *left, *right;
    tree(int x) {
        val = x;
        left = right = NULL;
    }
    tree *create() {
        tree *p;
        int x;
        cin >> x;
        if (x == -1)
            return NULL;
        p = new tree(x);
        cout << "Enter left child of " << x << " : ";
        p->left = create();
        cout << "Enter right child of " << x << " : ";
        p->right = create();
        return p;
    }
};

void disp(tree *root) {
    if (!root) return;
    disp(root->left);
    cout << root->val << " ";
    disp(root->right);
}
int main() {
    tree *root = new tree(-1);
    cout << "Please input the tree as asked (enter -1 to insert a NULL node)\n";
    cout << "Enter the root value : ";
    root = root->create();
    cout << "\nThe Inorder Sequence of the binary tree is : ";
    disp(root);
}