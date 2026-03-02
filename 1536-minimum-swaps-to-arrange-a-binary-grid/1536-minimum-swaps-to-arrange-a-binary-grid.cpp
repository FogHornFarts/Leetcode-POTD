class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailing(n, 0);
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 0)
                    cnt++;
                else
                    break;
            }
            trailing[i] = cnt;
        }
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int need = n - 1 - i;
            int j = i;
            while (j < n && trailing[order[j]] < need)
                ++j;
            if (j == n)
                return -1;
            ans += j - i;
            int temp = order[j];
            for (int k = j; k > i; --k) {
                order[k] = order[k - 1];
            }
            order[i] = temp;
        }
        return ans;
    }
};