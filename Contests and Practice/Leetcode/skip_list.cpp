const long long M = 1e9 + 7;
const int INF = 2147483647;
const long long INFLL = 9223372036854775807ll;
#pragma region Template Start
#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<ll, ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vpii = vector<pii>;
using vpll = vector<pll>;
#define endl '\n'
#define nl cout << '\n'
#define pb push_back
#define pob pop_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define FIX(number, digits) fixed << setprecision(digits) << number  // use in cout
#define fok(i, k, n) for (ll i = k; i < n; i++)
#define Fok(i, k, n) for (ll i = n; i >= k; i--)
#define fo(i, n) for (ll i = 0; i < n; i++)
#define Fo(i, n) for (ll i = n; i >= 0; i--)
#define CHK(s, k) (s.find(k) != s.end())
#define all(v) v.begin(), v.end()
#define allg(v) v.rbegin(), v.rend()
#define Sort(v) sort(all(v))
#define Sortg(v) sort(allg(v))
#define sz(v) (static_cast<ll>(v.size()))
#define bs(v, val) binary_search(all(v), val)
#define lb(v, val) lower_bound(all(v), val)
#define ub(v, val) upper_bound(all(v), val)
#define setbits(x) __builtin_popcount(x)
#define start_clock() auto start_time = std::chrono::high_resolution_clock::now()
#define measure()                                              \
    auto end_time = std::chrono::high_resolution_clock::now(); \
    cerr << (end_time - start_time) / std::chrono::milliseconds(1) << "ms" << endl

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define fileio                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)

#pragma endregion Template End
/*-----------------------------------------UTILITY FUNCTIONS------------------------------------------*/
inline ll ceil(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }   // divide a by b rounded up
inline ll floor(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }  // divide a by b rounded down
/*------------------------------------------END OF TEMPLATE-------------------------------------------*/

struct Node {
    int val;
    Node* next;
    Node* below;
    Node(int val, Node* next = nullptr, Node* below = nullptr) {
        this->val = val;
        this->next = next;
        this->below = below;
    }
};

class Skiplist {
    Node* root;
    int numNodes;
    int numLevels;

   public:
    Skiplist() {
        // by default, -inf -> +inf is the starting point
        root = new Node(-INF, new Node(INF));
        numNodes = numLevels = 0;
    }

    bool search(int target) {
        return this->_search(target, root);
    }

    void add(int num) {
        cout << "Adding: " << num << endl;
        numNodes++;
        if (floor(log2(numNodes)) + 1 > numLevels) {
            this->addNewLevel();
            numLevels++;
        }
        this->_add(num, root->below);
    }

    bool erase(int num) {
        cout << "Erasing: " << num << endl;
        Node* nodeToErase = this->_erase(num, root->below, nullptr);
        if (nodeToErase) {
            cout << "Erased: " << num << endl;
            numNodes--;
            delete nodeToErase;
            removeEmptyLevels();
            return true;
        }
        return false;
    }

    void print() const {
        cout << "Printing Skip List with " << numNodes << " nodes and " << numLevels << " levels" << endl;
        Node* level = root;
        while (level) {
            Node* node = level;
            while (node) {
                if (node->val == -INF) {
                    std::cout << "-INF";
                } else if (node->val == INF) {
                    std::cout << "+INF";
                } else {
                    std::cout << std::setw(4) << node->val;
                }

                node = node->next;
                if (node) std::cout << " -> ";
            }
            std::cout << endl;
            level = level->below;
        }
    }

   private:
    bool flipCoinReturnedHead() {
        // returns true for head, false for tails
        return rand() % 2;
    }

    void addNewLevel() {
        Node* currentNode = root;
        while (currentNode->below)
            currentNode = currentNode->below;
        Node* previousNode = nullptr;
        while (currentNode) {
            Node* newNode = new Node(currentNode->val);
            currentNode->below = newNode;
            if (previousNode)
                previousNode->next = newNode;
            previousNode = newNode;
            currentNode = currentNode->next;
        }
    }

    void removeEmptyLevels() {
        // returns the first and last nodes of the first list after removing empty ones (-inf -> inf)
        Node* currentNode = root->below;
        if (!currentNode || currentNode->next->next)
            return;
        while (currentNode && currentNode->next->next == nullptr) {
            // remove this level
            Node* tempHead = currentNode;
            currentNode = currentNode->below;
            delete tempHead->next;
            delete tempHead;
        }
        Node* first = currentNode;
        Node* last = currentNode;
        while (last && last->next)
            last = last->next;
        root->below = first;
        root->next->below = last;
    }

    Node* addNewNode(int val, Node* currentNode, Node* belowNode) {
        // adds a new node ahead of currentNode and above belowNode
        Node* newNode = new Node(val, currentNode->next, belowNode);
        currentNode->next = newNode;
        return newNode;
    }

    bool _search(const int& target, Node* currentNode) {
        if (!currentNode)
            return false;
        if (currentNode->val == target)
            return true;
        if (currentNode->next->val <= target)
            return this->_search(target, currentNode->next);
        return this->_search(target, currentNode->below);
    }

    Node* _add(const int& num, Node* currentNode) {
        if (currentNode->next->val < num) {
            return _add(num, currentNode->next);  // move forward and add the node
        }
        if (!currentNode->below) {
            Node* newlyAddedNode = addNewNode(num, currentNode, nullptr);
            return (flipCoinReturnedHead() ? newlyAddedNode : nullptr);
        }
        Node* addedNode = _add(num, currentNode->below);
        if (addedNode) {
            // add it again at this level and propagate it upwards with 1/2 probability
            Node* newlyAddedNode = addNewNode(num, currentNode, addedNode);
            return (flipCoinReturnedHead() ? newlyAddedNode : nullptr);
        }
        return nullptr;
    }

    Node* _erase(const int& num, Node* currentNode, Node* previousNode) {
        if (!currentNode)
            return nullptr;
        if (currentNode->val == num) {
            // this means currentNode will be erased, also every node below this node as well
            // erase children nodes first, get the latest erased child node to safely delete
            while (previousNode && previousNode->next != currentNode)
                previousNode = previousNode->next;
            Node* nodeToErase = this->_erase(num, currentNode->below, previousNode->below);
            // remove currentNode
            previousNode->next = currentNode->next;
            currentNode->below = nullptr;  // removing reference for safety
            if (nodeToErase)
                delete nodeToErase;
            return currentNode;  // to be erased by parent
        }
        if (currentNode->next->val <= num) {
            Node* nodeToErase = this->_erase(num, currentNode->next, currentNode);
            return nodeToErase;  // propagate upwards
        }
        // move below
        Node* nodeToErase = this->_erase(num, currentNode->below, (previousNode ? previousNode->below : nullptr));
        return nodeToErase;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */

void assert(bool val) {
    if (!val) {
        throw exception();
    }
}

void solve() {
    Skiplist a;
    a.add(16);
    a.add(5);
    a.add(14);
    a.add(13);
    a.add(0);
    a.add(3);
    a.add(12);
    a.add(9);
    a.add(12);

    a.print();
    assert(a.erase(3) == true);    // 3 is in the list, should erase successfully
    assert(a.search(6) == false);  // 6 is not in the list
    assert(a.search(7) == false);  // 7 is not in the list
    a.add(0);
    a.print();
    assert(a.erase(0) == true);    // 0 is in the list, should erase successfully
    assert(a.erase(1) == false);   // 1 is not in the list, should return false
    assert(a.erase(10) == false);  // 10 is not in the list, should return false
    a.add(5);
    a.print();
    assert(a.search(12) == true);  // 12 is in the list
    assert(a.search(7) == false);  // 7 is not in the list
    assert(a.search(16) == true);  // 16 is in the list
    assert(a.erase(7) == false);   // 7 is not in the list, should return false
    assert(a.search(0) == false);  // 0 was erased earlier, should return false
    a.add(9);
    a.print();
    a.add(16);
    a.print();
    assert(a.erase(3) == false);   // 3 was erased earlier, should return false
    assert(a.search(2) == false);  // 2 is not in the list
    a.add(17);
    a.print();
    assert(a.erase(2) == false);   // 2 is not in the list
    assert(a.erase(17) == true);   // 17 is in the list, should erase successfully
    assert(a.search(0) == false);  // 0 is not in the list
    assert(a.search(9) == true);   // 9 is in the list
    assert(a.erase(14) == true);   // 14 is in the list, should erase successfully
    assert(a.erase(1) == false);   // 1 is not in the list
    assert(a.erase(6) == false);   // 6 is not in the list
    a.add(1);
    a.print();
    assert(a.erase(16) == true);   // 16 is in the list, should erase successfully
    assert(a.search(9) == true);   // 9 is in the list
    assert(a.erase(10) == false);  // 10 is not in the list
    assert(a.erase(9) == true);    // 9 is in the list, should erase successfully
    assert(a.erase(2) == false);   // 2 is not in the list
    assert(a.search(3) == false);  // 3 was erased earlier, should return false
    a.add(16);
    a.print();
    a.add(15);
    a.print();
    assert(a.erase(12) == true);  // 12 is in the list, should erase successfully
    assert(a.erase(7) == false);  // 7 is not in the list
    assert(a.erase(4) == false);  // 4 is not in the list
    a.add(3);
    a.print();
    assert(a.erase(2) == false);  // 2 is not in the list
    assert(a.erase(1) == true);   // 1 is in the list, should erase successfully
    a.add(14);
    a.print();
    a.add(13);
    a.print();
    a.add(12);
    a.print();
    assert(a.search(3) == true);   // 3 is in the list
    assert(a.search(6) == false);  // 6 is not in the list
    a.add(17);
    assert(a.erase(2) == false);   // 2 is not in the list
    assert(a.erase(3) == true);    // 3 is in the list, should erase successfully
    assert(a.search(14) == true);  // 14 is in the list
    a.add(11);
    assert(a.search(0) == false);  // 0 is not in the list
    a.add(13);
    assert(a.erase(2) == false);    // 2 is not in the list
    assert(a.erase(1) == false);    // 1 was erased earlier, should return false
    assert(a.search(10) == false);  // 10 is not in the list
    a.add(17);
    assert(a.search(0) == false);  // 0 is not in the list
    a.add(5);
    assert(a.search(8) == false);  // 8 is not in the list
    a.add(9);
    assert(a.search(8) == false);   // 8 is not in the list
    assert(a.erase(11) == true);    // 11 is in the list, should erase successfully
    assert(a.search(10) == false);  // 10 is not in the list
    assert(a.search(11) == false);  // 11 was erased earlier, should return false
    a.add(10);
    assert(a.search(11) == false);  // 11 was erased earlier, should return false
    assert(a.search(10) == true);   // 10 is in the list
    a.add(9);
    a.add(8);
    assert(a.search(15) == true);  // 15 is in the list
    assert(a.search(14) == true);  // 14 is in the list
    a.add(1);
    a.add(6);
    assert(a.search(17) == true);  // 17 is in the list
    a.add(16);
    assert(a.search(13) == true);  // 13 is in the list
    assert(a.search(4) == false);  // 4 is not in the list
    a.add(5);
    a.add(4);
    assert(a.search(17) == true);  // 17 is in the list
    assert(a.search(16) == true);  // 16 is in the list
    assert(a.search(7) == false);  // 7 is not in the list
    assert(a.search(14) == true);  // 14 is in the list
    assert(a.search(1) == true);   // 1 is in the list

    std::cout << "All tests passed!" << endl;
}

int main() {
#ifdef ONLINE_JUDGE
    fastio;
#endif
    ll tes = 1;
    // cin >> tes;
    for (ll t = 1; t <= tes; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}