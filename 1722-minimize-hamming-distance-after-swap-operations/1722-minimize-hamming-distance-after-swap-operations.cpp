class Solution {
public:
    class DSU {
        public:
        vector<int> parent, rankv;
        DSU(int n) {
            parent.resize(n);
            rankv.resize(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        } 
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY){
                return;
            }
            if (rankv[rootX] < rankv[rootY]) {
                parent[rootX] = rootY;
            } else if (rankv[rootX] > rankv[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rankv[rootX]++;
            }
        }


    };
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
         int n = source.size();
        DSU dsu(n);

        for (auto &edge : allowedSwaps) {
            int a = edge[0];
            int b = edge[1];
            dsu.unite(a, b);
        }
        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            groups[root].push_back(i);
        }

        int answer = 0;
        for (auto &entry : groups) {
            vector<int> &indices = entry.second;
            unordered_map<int, int> freq;
            for (int idx : indices) {
                freq[source[idx]]++;
            }
            for (int idx : indices) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    answer++;
                }
            }
        }
        return answer;
    }
};