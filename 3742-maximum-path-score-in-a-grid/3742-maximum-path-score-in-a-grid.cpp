class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, int k, int n, int m,
              vector<vector<vector<int>>>& dp) {

        if (i >= n || j >= m)
            return -1;

        int cost = (grid[i][j] == 0 ? 0 : 1);
        k -= cost;

        if (k < 0)
            return -1;

        if (i == n - 1 && j == m - 1) {
            return grid[i][j];
        }

        if (dp[i][j][k] != -2)
            return dp[i][j][k];

        int right = solve(i, j + 1, grid, k, n, m, dp);
        int down = solve(i + 1, j, grid, k, n, m, dp);

        int best = max(right, down);

        if (best == -1)
            return dp[i][j][k] = -1;

        return dp[i][j][k] = grid[i][j] + best;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 1, -2)));

        return solve(0, 0, grid, k, n, m, dp);
    }
};