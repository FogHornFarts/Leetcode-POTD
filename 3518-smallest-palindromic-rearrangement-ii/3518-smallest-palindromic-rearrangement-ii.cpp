class Solution {
public:
    using ll = long long;
    const long long LIM = 1000000000000LL;

    long long C(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);
        long long ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans > LIM) return LIM;
        }
        return ans;
    }

    long long countWays(vector<int>& f) {
        int tot = 0;
        for (int x : f) tot += x;

        __int128 ans = 1;
        int rem = tot;

        for (int x : f) {
            if (!x) continue;

            ans *= C(rem, x);

            if (ans > LIM)
                return LIM;

            rem -= x;
        }

        return (long long)ans;
    }

    string smallestPalindrome(string s, long long k) {
        vector<int> cnt(26), half(26);

        for (char c : s)
            cnt[c - 'a']++;

        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
            if (cnt[i] % 2)
                mid += char('a' + i);
        }

        if (countWays(half) < k)
            return "";

        string left = "";
        int len = s.size() / 2;

        while ((int)left.size() < len) {
            for (int i = 0; i < 26; i++) {
                if (half[i] == 0)
                    continue;

                half[i]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    left += char('a' + i);
                    break;
                }

                k -= ways;
                half[i]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};