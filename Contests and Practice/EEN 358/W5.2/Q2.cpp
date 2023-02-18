#include <cmath>
#include <iostream>
using namespace std;

struct tree {
    int val, lcount;
    tree *left, *right;
    tree(int x) {
        val = x;
        lcount = 0;
        left = right = NULL;
    }
};
tree* parent(tree* root, tree* p) {
    if (!root) return NULL;
    if (root == p) return root;
    if (root->left == p || root->right == p)
        return root;
    tree* lef = parent(root->left, p);
    tree* rig = parent(root->right, p);
    if (lef) return lef;
    return rig;
}
tree* findkth(int k, tree* root) {
    if (!root) return NULL;
    if (root->val != -1) return root;
    if (root->lcount < k)
        return findkth(k - root->lcount, root->right);
    return findkth(k, root->left);
}

tree* deletekth(int k, tree* root) {
    tree* p = findkth(k, root);
    if (p == root) {
        p->lcount--;
        return NULL;
    }
    tree* par = parent(root, p);
    while (par != p) {
        if (par->left == p)
            par->lcount--;
        p = par;
        par = parent(root, p);
    }
    return root;
}

tree* build(int curlev, int reqlev, int& i, int n, int* a) {
    if (i >= n) return NULL;
    if (curlev == reqlev) {
        return new tree(a[i++]);
    }
    tree* root = new tree(-1);
    root->left = build(curlev + 1, reqlev, i, n, a);
    root->right = build(curlev + 1, reqlev, i, n, a);
    return root;
}
int siz(tree* root) {
    if (!root) return 0;
    if (!root->left && !root->right)
        return 1;
    int lef = siz(root->left), rig = siz(root->right);
    root->lcount = lef;
    return lef + rig;
}

tree* buildtree(int n) {
    int reqlev = ceil(log2(n));
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    int i = 0;
    tree* root = build(0, reqlev, i, n, a);
    siz(root);
    return root;
}
void Josh(tree* root, int k, int i, int n) {
    if (n == 1) {
        cout << "Last Person Standing is : ";
        cout << findkth(1, root)->val << endl;
        return;
    }
    i = ((i + k - 1) % n);
    root = deletekth(i + 1, root);
    Josh(root, k, i, n - 1);
}
int main() {
    int n, k;
    cout << "Number of persons and Killing pattern (n and k)\n";
    cin >> n >> k;
    tree* root = buildtree(n);
    Josh(root, k, 0, n);
}