class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int mod = 1e9 + 7;
        int li = limit + 1;
        vector<vector<long long>> dp0(zero + 1, vector<long long>(one + 1, 0));
        vector<vector<long long>> dp1(zero + 1, vector<long long>(one + 1, 0));
        for (int i = 1; i <= min(zero, limit); i++) {
            dp0[i][0] = 1;
        }
        for (int j = 1; j <= min(one, limit); j++) {
            dp1[0][j] = 1;
        }
        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                long long sub1 = (i >= li ? dp1[i - li][j] : 0);
                dp0[i][j] = (dp0[i - 1][j] + dp1[i - 1][j] - sub1 + mod) % mod;
                long long sub2 = (j >= li ? dp0[i][j - li] : 0);
                dp1[i][j] = (dp0[i][j - 1] + dp1[i][j - 1] - sub2 + mod) % mod;
            }
        }
        return (dp0[zero][one] + dp1[zero][one]) % mod;
    }
};