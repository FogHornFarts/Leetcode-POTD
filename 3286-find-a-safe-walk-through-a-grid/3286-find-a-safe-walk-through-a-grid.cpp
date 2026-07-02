class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        deque<pair<int, int>> dq;

        dq.push_front({0, 0});
        res[0][0] = grid[0][0];

        while (!dq.empty()) {
            auto [i, j] = dq.front();
            dq.pop_front();

            for (int k = 0; k < 4; k++) {
                int r = i + dr[k];
                int c = j + dc[k];

                if (r < 0 || c < 0 || r >= n || c >= m)
                    continue;

                if (res[i][j] + grid[r][c] < res[r][c]) {
                    res[r][c] = res[i][j] + grid[r][c];

                    if (grid[r][c] == 0)
                        dq.push_front({r, c});
                    else
                        dq.push_back({r, c});
                }
            }
        }

        return health > res[n - 1][m - 1];
    }
};