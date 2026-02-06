class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());

        int left = 0;
        int n = nums.size();

        for (int right = 0; right < n; right++) {
            if ((long long)nums[left] * k < nums[right]) {
                left++;
            }
        }

        return left;
    }
};