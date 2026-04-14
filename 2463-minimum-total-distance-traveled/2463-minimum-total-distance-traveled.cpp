class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int r = robot.size();
        int f = factory.size();
        vector<vector<long long>> dp(r + 1, vector<long long>(f + 1, LLONG_MAX / 2));

        for (int j = 0; j <= f; j++) dp[0][j] = 0;

        for (int j = 1; j <= f; j++) {
            int pos = factory[j-1][0];
            int limit = factory[j-1][1];
            for (int i = 0; i <= r; i++) {
                dp[i][j] = dp[i][j-1];
                long long dist = 0;
                for (int k = 1; k <= limit && i - k >= 0; k++) {
                    dist += llabs((long long)robot[i - k] - pos);
                    dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + dist);
                }
            }
        }
        return dp[r][f];
    }
};