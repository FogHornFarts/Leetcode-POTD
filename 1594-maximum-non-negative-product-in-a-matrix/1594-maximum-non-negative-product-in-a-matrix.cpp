class Solution {
public:
    int maxProductPath(vector<vector<int>>& b) {
        int n = b.size();
        int m = b[0].size();
        const long long MOD = 1e9 + 7;

        vector<vector<long long>> dpMax(n, vector<long long>(m));
        vector<vector<long long>> dpMin(n, vector<long long>(m));

        dpMax[0][0] = dpMin[0][0] = b[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0){
                    continue;
                }
                long long val = b[i][j];
                long long mx = LLONG_MIN;
                long long mn = LLONG_MAX;

                if (i > 0) {
                    mx = max(mx, max(dpMax[i - 1][j] * val, dpMin[i - 1][j] * val));
                    mn = min(mn, min(dpMax[i - 1][j] * val, dpMin[i - 1][j] * val));
                }

                if (j > 0) {
                    mx = max(mx, max(dpMax[i][j - 1] * val, dpMin[i][j - 1] * val));
                    mn = min(mn, min(dpMax[i][j - 1] * val, dpMin[i][j - 1] * val));
                }

                dpMax[i][j] = mx;
                dpMin[i][j] = mn;
            }
        }
        if (dpMax[n - 1][m - 1] < 0){
            return -1;
        }
        return dpMax[n - 1][m - 1] % MOD;
    }
};