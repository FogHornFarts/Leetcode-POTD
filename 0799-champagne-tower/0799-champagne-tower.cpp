class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> dp(102, 0.0);
        dp[0] = poured;

        for(int r = 0; r < query_row; r++) {
            vector<double> next(102, 0.0);

            for(int c = 0; c <= r; c++) {
                double overflow = max(0.0, dp[c] - 1.0);
                if(overflow > 0) {
                    next[c]     += overflow / 2.0;
                    next[c + 1] += overflow / 2.0;
                }
            }

            dp = next;
        }

        return min(1.0, dp[query_glass]);
    }
};
