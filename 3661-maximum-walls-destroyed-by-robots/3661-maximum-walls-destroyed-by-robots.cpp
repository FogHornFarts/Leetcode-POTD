class Solution {
public:
    // function to count walls in range [l, r]
    int countWalls(vector<int>& walls, int l, int r) {
        if (l > r){
            return 0;
        }
        int left = lower_bound(walls.begin(), walls.end(), l) - walls.begin();
        int right = upper_bound(walls.begin(), walls.end(), r) - walls.begin();
        return right - left;
    }

    int maxWalls(vector<int>& robots, vector<int>& d, vector<int>& walls) {
        int n = robots.size();

        // store (position, distance)
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {robots[i], d[i]};
        }

        sort(arr.begin(), arr.end());
        sort(walls.begin(), walls.end());

        // dp[i][0] = left, dp[i][1] = right
        vector<vector<int>> dp(n, vector<int>(2, 0));
        // first robot
        dp[0][0] = countWalls(walls, arr[0].first - arr[0].second, arr[0].first);
        if (n > 1) {
            int rightEnd = min(arr[0].first + arr[0].second, arr[1].first - 1);
            dp[0][1] = countWalls(walls, arr[0].first, rightEnd);
        } else {
            dp[0][1] = countWalls(walls, arr[0].first, arr[0].first + arr[0].second);
        }
        // process remaining robots
        for (int i = 1; i < n; i++) {
            // shoot RIGHT
            int rightEnd;
            if (i < n - 1) {
                rightEnd = min(arr[i].first + arr[i].second, arr[i + 1].first - 1);
            } else {
                rightEnd = arr[i].first + arr[i].second;
            }

            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + countWalls(walls, arr[i].first, rightEnd);

            // shoot LEFT (normal case)
            int leftStart = max(arr[i].first - arr[i].second, arr[i - 1].first + 1);
            int leftEnd = arr[i].first;

            dp[i][0] = dp[i - 1][0] + countWalls(walls, leftStart, leftEnd);

            // handle overlap if previous was RIGHT
            int overlapStart = leftStart;
            int overlapEnd = min(arr[i - 1].first + arr[i - 1].second, arr[i].first - 1);

            int temp = dp[i - 1][1] + countWalls(walls, leftStart, leftEnd) - countWalls(walls, overlapStart, overlapEnd);
            dp[i][0] = max(dp[i][0], temp);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};