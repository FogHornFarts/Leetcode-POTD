class Solution {
public:
    struct Fenwick {
        int n;
        vector<long long> bit;
        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void add(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        long long query(int idx) {
            long long res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = n + 2;
        Fenwick fw(2 * n + 5);

        int pref = 0;
        fw.add(pref + offset, 1);

        long long ans = 0;

        for (int x : nums) {
            pref += (x == target ? 1 : -1);

            ans += fw.query(pref + offset - 1);

            fw.add(pref + offset, 1);
        }

        return ans;
    }
};