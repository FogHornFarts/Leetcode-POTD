class Solution {
public:
    int minOperations(string s, int k) {
        int zerocount = 0;
        for (auto &i : s)
            if (i == '0')
                zerocount++;

        int n = s.size();
        if (zerocount == 0)
            return 0;
        if (k == n)
            return (zerocount == n) ? 1 : -1;

        int ans = INT_MAX;

        if (zerocount % 2 == 0) {
            int m = max((zerocount + k - 1) / k, (zerocount + n - k - 1) / (n - k));
            ans = (m % 2 == 0) ? m : m + 1;
        }

        if (zerocount % 2 == k % 2) {
            int m = max((zerocount + k - 1) / k, (n - zerocount + n - k - 1) / (n - k));
            ans = min(ans, (m % 2 == 1) ? m : m + 1);
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};