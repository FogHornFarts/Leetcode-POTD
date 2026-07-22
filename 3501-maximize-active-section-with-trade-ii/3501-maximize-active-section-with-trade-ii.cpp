class SparseTable {
public:
    vector<vector<int>> st;

    SparseTable(vector<int>& a) {
        st.push_back(a);
        for (int p = 1; (1 << p) <= a.size(); p++) {
            vector<int> cur;
            int len = 1 << p;
            int half = len >> 1;

            for (int i = 0; i + len <= a.size(); i++) {
                cur.push_back(max(st[p-1][i], st[p-1][i + half]));
            }
            st.push_back(cur);
        }
    }

    int query(int l, int r) {
        if (l > r) return 0;
        int k = __lg(r - l + 1);
        return max(st[k][l], st[k][r - (1 << k) + 1]);
    }
};


class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {

        int n = s.size();
        int ones = count(s.begin(), s.end(), '1');

        vector<int> len, L, R;

        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;

            if (s[i] == '0') {
                len.push_back(j - i);
                L.push_back(i);
                R.push_back(j - 1);
            }

            i = j;
        }

        int m = len.size();

        if (m < 2)
            return vector<int>(queries.size(), ones);

        vector<int> merge(m - 1);

        for (int i = 0; i < m - 1; i++)
            merge[i] = len[i] + len[i + 1];

        SparseTable st(merge);

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0], r = q[1];

            int i = lower_bound(R.begin(), R.end(), l) - R.begin();
            int j = upper_bound(L.begin(), L.end(), r) - L.begin() - 1;


            if (i >= j || i >= m || j < 0) {
                ans.push_back(ones);
                continue;
            }


            int first = R[i] - max(L[i], l) + 1;
            int last = min(R[j], r) - L[j] + 1;


            if (i + 1 == j) {
                ans.push_back(ones + first + last);
                continue;
            }


            int best = max({
                first + len[i + 1],
                len[j - 1] + last,
                st.query(i + 1, j - 2)
            });


            ans.push_back(ones + best);
        }

        return ans;
    }
};