#include <iostream>
#include <queue>
using namespace std;

const int MX = 1000;
int leftt[MX], rightt[MX], val[MX];

int create(int root = 0) {
    int x;
    cin >> x;
    val[root] = x;
    if (x == -1)
        return -1;
    cout << "Enter left child of " << x << " : ";
    int lef = create(2 * root + 1);
    cout << "Enter right child of " << x << " : ";
    int rig = create(2 * root + 2);
    leftt[root] = lef;
    rightt[root] = rig;
    return root;
}
void disp(int root) {
    if (val[root] == -1) return;
    disp(leftt[root]);
    cout << val[root] << " ";
    disp(rightt[root]);
}

int count_leaves(int root) {
    if (val[root] == -1) return 0;
    if (val[leftt[root]] == -1 && val[rightt[root]] == -1) return 1;
    return count_leaves(leftt[root]) + count_leaves(rightt[root]);
}
int depth(int root) {
    if (val[root] == -1) return 0;
    return 1 + max(depth(leftt[root]), depth(rightt[root]));
}
bool is_father(int root, int par, int child) {
    if (val[root] == -1) return false;
    if (val[root] == par) {
        int x = (val[leftt[root]] != -1) ? val[leftt[root]] : -1;
        int y = (val[rightt[root]] != -1) ? val[rightt[root]] : -1;
        return (x == child || y == child) ? true : false;
    }
    bool lef = is_father(leftt[root], par, child);
    return (lef) ? true : is_father(rightt[root], par, child);
}
void chkfather(int root, int par, int child) {
    bool s = is_father(root, par, child);
    if (s)
        cout << par << " is the father of " << child << endl;
    else
        cout << par << " is not the father of " << child << endl;
}
bool is_sibling(int root, int n1, int n2) {
    if (val[root] == -1) return false;
    if (val[root] != -1 && val[leftt[root]] != -1 && val[rightt[root]] != -1) {
        if (val[leftt[root]] == n1 && val[rightt[root]] == n2)
            return true;
        if (val[rightt[root]] == n1 && val[leftt[root]] == n2)
            return true;
    }
    bool lef = is_sibling(leftt[root], n1, n2);
    return (lef) ? true : is_sibling(rightt[root], n1, n2);
}
void chksibling(int root, int n1, int n2) {
    bool s = is_sibling(root, n1, n2);
    if (s)
        cout << n1 << " is the sibling of " << n2 << endl;
    else
        cout << n1 << " is not the sibling of " << n2 << endl;
}
int main() {
    for (int i = 0; i < MX; i++) {
        val[i] = leftt[i] = rightt[i] = -1;
    }
    int root = 0;
    cout << "Please input the tree as asked (enter -1 to insert a NULL node)\n";
    cout << "Enter the root value : ";
    create(root);
    cout << "\nThe Inorder Sequence of the binary tree is : ";
    disp(root);
    cout << endl;
    
    cout << "The number of leaves are : " << count_leaves(root) << endl;
    cout << "The depth of the tree is : " << depth(root) << endl;

    chkfather(root, 3, 6);
    chkfather(root, 6, 7);
    chkfather(root, 3, 7);

    chksibling(root, 2, 3);
    chksibling(root, 1, 6);
    chksibling(root, 4, 5);
}