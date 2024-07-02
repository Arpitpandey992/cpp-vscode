#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=1579 lang=cpp
 *
 * [1579] Remove Max Number of Edges to Keep Graph Fully Traversable
 */

// @lc code=start
class DSU {
   private:
    int n;  // Elements present are from 0 to n-1
    vector<int> par, rank;

   public:
    int totalSets;
    DSU(int n) {
        this->n = n;
        totalSets = n;
        par.resize(n, -1);
        rank.resize(n, 0);
        iota(par.begin(), par.end(), 0);
    }
    int fin(int a) {
        if (par[a] == a)
            return a;
        return par[a] = fin(par[a]);
    }
    bool uni(int a, int b) {
        a = fin(a);
        b = fin(b);
        if (a == b) return false;
        if (rank[a] < rank[b])
            par[a] = b;
        else if (rank[b] < rank[a])
            par[b] = a;
        else {
            rank[a]++;
            par[b] = a;
        }
        totalSets--;
        return true;
    }
    void clear() {
        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
        totalSets = n;
    }
};

class Solution {
    int maxNumEdgesToRemoveInPartiallyConnectedGraph(const int& n, vector<pair<int, int>>& edges, DSU& originalDsu) {
        DSU dsu = originalDsu;  // make a copy
        int removedEdges = 0;
        for (auto& [node1, node2] : edges) {
            if (dsu.fin(node1) != dsu.fin(node2)) {
                dsu.uni(node1, node2);
            } else {
                removedEdges++;
            }
        }
        int commonParent = dsu.fin(0);
        for (int node = 1; node < n; node++) {
            if (dsu.fin(node) != commonParent)
                return -1;
        }
        return removedEdges;
    }

   public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<pair<int, int>> aliceEdges, bobEdges, commonEdges;
        for (auto& edge : edges) {
            switch (edge[0]) {
                case 1:
                    aliceEdges.push_back({edge[1] - 1, edge[2] - 1});
                    break;
                case 2:
                    bobEdges.push_back({edge[1] - 1, edge[2] - 1});
                    break;
                case 3:
                    commonEdges.push_back({edge[1] - 1, edge[2] - 1});
                    break;
            }
        }
        DSU dsu(n);
        int commonRemovedEdges = 0;
        for (auto& [node1, node2] : commonEdges) {
            if (dsu.fin(node1) != dsu.fin(node2)) {
                dsu.uni(node1, node2);
            } else {
                commonRemovedEdges++;
            }
        }
        int aliceRemoveEdges = maxNumEdgesToRemoveInPartiallyConnectedGraph(n, aliceEdges, dsu);
        if (aliceRemoveEdges == -1)
            return -1;
        int bobRemoveEdges = maxNumEdgesToRemoveInPartiallyConnectedGraph(n, bobEdges, dsu);
        if (bobRemoveEdges == -1)
            return -1;
        return commonRemovedEdges + aliceRemoveEdges + bobRemoveEdges;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> edges = {{3, 1, 2}, {3, 2, 3}, {1, 1, 3}, {1, 2, 4}, {1, 1, 2}, {2, 3, 4}};
    Solution sol;
    sol.maxNumEdgesToRemove(4, edges);
}