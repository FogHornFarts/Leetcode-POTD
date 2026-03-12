class Solution {
public:

    struct DSU {
        vector<int> parent;
        int groups;
        DSU(int n) {
            parent.resize(n);
            for (int i = 0; i < n; i++) parent[i] = i;
            groups = n;
        }
        int find(int node) {
            if (parent[node] == node) return node;
            return parent[node] = find(parent[node]);
        }
        bool unite(int a, int b) {
            int rootA = find(a);
            int rootB = find(b);

            if (rootA == rootB) return false;

            parent[rootB] = rootA;
            groups--;
            return true;
        }
    };
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        vector<int> mustStrength;
        vector<int> optStrength;
        vector<vector<int>> mustEdges;
        vector<vector<int>> optEdges;
        for (auto &edge : edges) {
            if (edge[3] == 1) {
                mustEdges.push_back(edge);
            } else {
                optEdges.push_back(edge);
            }
        }
        for (auto &edge : mustEdges) {
            if (dsu.unite(edge[0], edge[1]) == false) {
                return -1;
            }
            mustStrength.push_back(edge[2]);
        }
        sort(optEdges.begin(), optEdges.end(),
        [](auto &a, auto &b) {
            return (long long)a[2] * 2 > (long long)b[2] * 2;
        });
        for (auto &edge : optEdges) {
            if (dsu.unite(edge[0], edge[1]) == true) {
                optStrength.push_back(edge[2]);
            }
        }
        if (dsu.groups > 1) {
            return -1;
        }
        sort(optStrength.begin(), optStrength.end());
        int usedUpgrades = 0;
        for (int i = 0; i < optStrength.size() && usedUpgrades < k; i++) {
            optStrength[i] = optStrength[i] * 2;
            usedUpgrades++;
        }
        int minEdgeStrength = INT_MAX;
        for (auto val : mustStrength) {
            minEdgeStrength = min(minEdgeStrength, val);
        }
        for (auto val : optStrength) {
            minEdgeStrength = min(minEdgeStrength, val);
        }
        return minEdgeStrength;
    }
};