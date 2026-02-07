class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        const long long NEG = -(long long)4e18;

        long long dp0 = nums[0];   // start fresh at i
        long long dp1 = NEG;       // in 1st increasing segment
        long long dp2 = NEG;       // in decreasing segment
        long long dp3 = NEG;       // in 2nd increasing segment
        long long ans = NEG;

        for (int i = 1; i < (int)nums.size(); i++) {
            long long x = nums[i];

            if (nums[i] > nums[i - 1]) {
                // update dp3 first because it depends on old dp2
                if (dp3 != NEG) dp3 = dp3 + x;
                if (dp2 != NEG) dp3 = max(dp3, dp2 + x);

                // dp1 can extend or start from dp0
                if (dp1 != NEG) dp1 = dp1 + x;
                dp1 = max(dp1, dp0 + x);

                dp2 = NEG;
            }
            else if (nums[i] < nums[i - 1]) {
                // dp2 can extend or start from dp1
                if (dp2 != NEG) dp2 = dp2 + x;
                if (dp1 != NEG) dp2 = max(dp2, dp1 + x);

                dp1 = dp3 = NEG;
            }
            else {
                dp1 = dp2 = dp3 = NEG;
            }

            dp0 = x;
            ans = max(ans, dp3);
        }

        return ans;
    }
};
