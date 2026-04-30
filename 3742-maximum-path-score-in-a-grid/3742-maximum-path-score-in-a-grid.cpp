class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));

        int startCost = (grid[0][0] == 0 ? 0 : 1);
        if (k >= startCost)
            dp[0][0][k - startCost] = grid[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int rem = 0; rem <= k; rem++) {
                    if (dp[i][j][rem] == -1) continue;

                    if (j + 1 < m) {
                        int cost = (grid[i][j + 1] == 0 ? 0 : 1);
                        if (rem >= cost) {
                            dp[i][j + 1][rem - cost] = max(
                                dp[i][j + 1][rem - cost],
                                dp[i][j][rem] + grid[i][j + 1]
                            );
                        }
                    }

                    if (i + 1 < n) {
                        int cost = (grid[i + 1][j] == 0 ? 0 : 1);
                        if (rem >= cost) {
                            dp[i + 1][j][rem - cost] = max(
                                dp[i + 1][j][rem - cost],
                                dp[i][j][rem] + grid[i + 1][j]
                            );
                        }
                    }
                }
            }
        }

        int ans = -1;
        for (int rem = 0; rem <= k; rem++) {
            ans = max(ans, dp[n - 1][m - 1][rem]);
        }

        return ans;
    }
};