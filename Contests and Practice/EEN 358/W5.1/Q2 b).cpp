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

int count_leaves(tree *root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return count_leaves(root->left) + count_leaves(root->right);
}
int depth(tree *root) {
    if (!root) return 0;
    return 1 + max(depth(root->left), depth(root->right));
}
bool is_father(tree *root, int par, int child) {
    if (root == NULL) return false;
    if (root->val == par) {
        int x = (root->left) ? root->left->val : -1;
        int y = (root->right) ? root->right->val : -1;
        return (x == child || y == child) ? true : false;
    }
    bool lef = is_father(root->left, par, child);
    return (lef) ? true : is_father(root->right, par, child);
}
void chkfather(tree *root, int par, int child) {
    bool s = is_father(root, par, child);
    if (s)
        cout << par << " is the father of " << child << endl;
    else
        cout << par << " is not the father of " << child << endl;
}
bool is_sibling(tree *root, int n1, int n2) {
    if (root == NULL) return false;
    if (root && root->left && root->right) {
        if (root->left->val == n1 && root->right->val == n2)
            return true;
        if (root->right->val == n1 && root->left->val == n2)
            return true;
    }
    bool lef = is_sibling(root->left, n1, n2);
    return (lef) ? true : is_sibling(root->right, n1, n2);
}
void chksibling(tree *root, int n1, int n2) {
    bool s = is_sibling(root, n1, n2);
    if (s)
        cout << n1 << " is the sibling of " << n2 << endl;
    else
        cout << n1 << " is not the sibling of " << n2 << endl;
}
int main() {
    tree *root = new tree(-1);
    cout << "Please input the tree as asked (enter -1 to insert a NULL node)\n";
    cout << "Enter the root value : ";
    root = root->create();
    cout << "\nThe Inorder Sequence of the binary tree is : ";
    disp(root);
    cout << endl;
    cout << "The number of leaves are : " << count_leaves(root) << endl;
    cout << "The depth of the tree is : " << depth(root) << endl;
    chkfather(root, 2, 5);
    chkfather(root, 1, 4);
    chkfather(root, 2, 4);

    chksibling(root, 5, 6);
    chksibling(root, 2, 3);
    chksibling(root, 4, 5);
}