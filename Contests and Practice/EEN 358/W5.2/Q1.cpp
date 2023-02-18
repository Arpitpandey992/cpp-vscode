#include <cmath>
#include <iostream>
using namespace std;

int listcount;

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
void print_list(tree* root) {
    for (int i = 1; i <= listcount; i++) {
        tree* kth = findkth(i, root);
        if (kth == NULL)
            break;
        cout << kth->val << "->";
    }
    cout << endl;
}
int main() {
    cout << "Enter Number of elements : ";
    cin >> listcount;
    int n = listcount;
    int reqlev = ceil(log2(n));
    cout << "Enter " << n << " Elements\n";
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int i = 0;
    tree* root = build(0, reqlev, i, n, a);
    siz(root);
    cout << "What to do (-1 to exit)? \n"
         << "1 - Check Kth element\n"
         << "2 - Delete kth element\n"
         << "3 - Check list\n";
    while (1) {
        int p;
        cin >> p;
        if (p == 1) {
            cout << "Enter Position of number to find : ";
            int k;
            cin >> k;
            if (k <= listcount && k >= 1) {
                tree* kth = findkth(k, root);
                cout << kth->val << endl;

            } else
                cout << "element doesn't exist\n";
        } else if (p == 2) {
            cout << "Enter Position of number to find and delete : ";
            int k;
            cin >> k;
            tree* kth = findkth(k, root);
            if (k > listcount || k < 1)
                cout << "element doesn't exist\n";
            else {
                root = deletekth(k, root);
                listcount--;
                cout << "Deleted element at position = " << k << endl;
            }
        } else if (p == 3) {
            cout << "List is : ";
            print_list(root);
        } else
            break;
        cout << "Input Again (1/2/3/-1) : ";
    }
}