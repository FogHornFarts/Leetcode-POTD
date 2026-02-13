class Solution {
public:
    static int longestRun(const string &s) {
        int n = (int)s.size();
        int best = 1, len = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) len++;
            else {
                best = max(best, len);
                len = 1;
            }
        }
        return max(best, len);
    }

    static long long pack(int x, int y) {
        // bias to handle negatives safely
        static const long long bias = 1LL << 18;   // enough for n up to 1e5
        static const long long shift = 32;

        return ((long long)(x + bias) << shift) | (long long)(y + bias);
    }

    int longestBalanced(string s) {
        int n = (int)s.size();
        int ans = longestRun(s);

        unordered_map<long long, int> ab, bc, ca, abc;
        ab.reserve(n);
        bc.reserve(n);
        ca.reserve(n);
        abc.reserve(n);

        // prefix state at index -1
        ab[pack(0, 0)] = -1;   // (A-B, C)
        bc[pack(0, 0)] = -1;   // (B-C, A)
        ca[pack(0, 0)] = -1;   // (C-A, B)
        abc[pack(0, 0)] = -1;  // (B-A, C-A)

        int A = 0, B = 0, C = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') A++;
            else if (s[i] == 'b') B++;
            else C++;

            long long key;

            // --- 3 character balanced: A=B=C ---
            key = pack(B - A, C - A);
            auto it = abc.find(key);
            if (it != abc.end()) ans = max(ans, i - it->second);
            else abc[key] = i;

            // --- only a,b balanced (no c): A=B and C=0 ---
            key = pack(A - B, C);
            it = ab.find(key);
            if (it != ab.end()) ans = max(ans, i - it->second);
            else ab[key] = i;

            // --- only b,c balanced (no a): B=C and A=0 ---
            key = pack(B - C, A);
            it = bc.find(key);
            if (it != bc.end()) ans = max(ans, i - it->second);
            else bc[key] = i;

            // --- only c,a balanced (no b): C=A and B=0 ---
            key = pack(C - A, B);
            it = ca.find(key);
            if (it != ca.end()) ans = max(ans, i - it->second);
            else ca[key] = i;
        }

        return ans;
    }
};
