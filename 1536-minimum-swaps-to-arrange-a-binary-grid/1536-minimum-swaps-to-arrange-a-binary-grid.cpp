class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n, 0);
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 0) ++cnt;
                else break;
            }
            zeros[i] = cnt;
        }
        vector<int> order(n);
        for (int i = 0; i < n; ++i) order[i] = i;

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int need = n - 1 - i;
            int j = i;
            while (j < n && zeros[order[j]] < need) ++j;
            if (j == n) return -1; 
            ans += j - i;
            int tmp = order[j];
            for (int k = j; k > i; --k) {
                order[k] = order[k - 1];
            }
            order[i] = tmp;
        }
        return ans;
    }
};