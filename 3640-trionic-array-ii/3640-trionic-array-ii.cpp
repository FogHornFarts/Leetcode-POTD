class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long ans = LLONG_MIN;

        int left = 0, p = 0, q = 0;
        long long sum = nums[0];

        for (int right = 1; right < nums.size(); right++) {
            sum += nums[right];

            // start decreasing phase
            if (nums[right - 1] > nums[right]) {
                if (right >= 2 && nums[right - 2] < nums[right - 1]) {
                    p = right - 1;

                    // shrink left greedily
                    while (left < q || (nums[left] < 0 && left + 1 < p)) {
                        sum -= nums[left++];
                    }
                }
            }
            // start final increasing phase
            else if (nums[right - 1] < nums[right]) {
                if (right >= 2 && nums[right - 2] > nums[right - 1]) {
                    q = right - 1;
                }

                // valid trionic window exists
                if (left != p) {
                    ans = max(ans, sum);
                }
            }
            // equal → reset
            else {
                left = p = q = right;
                sum = nums[right];
            }
        }

        return ans;
    }
};
