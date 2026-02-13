#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = (int)s.size();
        int ans = 1;

        // Case 1: longest run of same char
        int run = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) run++;
            else run = 1;
            ans = max(ans, run);
        }

        int A = 0, B = 0, C = 0;

        // Maps store earliest index where state appeared
        unordered_map<long long, int> mpAB_C;
        unordered_map<long long, int> mpAC_B;
        unordered_map<long long, int> mpBC_A;
        unordered_map<long long, int> mpABC;

        auto pack2 = [&](int x, int y) -> long long {
            // shift to avoid negative collisions
            return ( (long long)(x + 200000) << 20 ) ^ (long long)(y + 200000);
        };

        // prefix at "index -1"
        mpAB_C[pack2(0, 0)] = -1; // (A-B=0, C=0)
        mpAC_B[pack2(0, 0)] = -1; // (A-C=0, B=0)
        mpBC_A[pack2(0, 0)] = -1; // (B-C=0, A=0)
        mpABC[pack2(0, 0)]  = -1; // (A-B=0, A-C=0)

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') A++;
            else if (s[i] == 'b') B++;
            else C++;

            // ---- 2 character cases ----
            // only a,b : need A-B same and C same
            long long key1 = pack2(A - B, C);
            if (mpAB_C.count(key1)) ans = max(ans, i - mpAB_C[key1]);
            else mpAB_C[key1] = i;

            // only a,c : need A-C same and B same
            long long key2 = pack2(A - C, B);
            if (mpAC_B.count(key2)) ans = max(ans, i - mpAC_B[key2]);
            else mpAC_B[key2] = i;

            // only b,c : need B-C same and A same
            long long key3 = pack2(B - C, A);
            if (mpBC_A.count(key3)) ans = max(ans, i - mpBC_A[key3]);
            else mpBC_A[key3] = i;

            // ---- 3 character case ----
            // need A-B same and A-C same
            long long key4 = pack2(A - B, A - C);
            if (mpABC.count(key4)) ans = max(ans, i - mpABC[key4]);
            else mpABC[key4] = i;
        }

        return ans;
    }
};
