class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        for(int i = 0; i < n; i++) {
            set<int> evenSet;
            set<int> oddSet;

            for(int j = i; j < n; j++) {

                if(nums[j] % 2 == 0) {
                    evenSet.insert(nums[j]);
                }
                else {
                    oddSet.insert(nums[j]);
                }

                if(evenSet.size() == oddSet.size()) {
                    int len = j - i + 1;
                    maxLen = max(maxLen, len);
                }
            }
        }

        return maxLen;
    }
};