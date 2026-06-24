class Solution {
public:
    static constexpr long long MOD = 1'000'000'007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<vector<long long>> T(m, vector<long long>(m, 0));

        for (int j = 0; j < m; j++) {
            for (int i = m - j; i < m; i++) {
                T[i][j] = 1;
            }
        }

        auto powT = matPow(T, n - 1);

        long long total = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                total = (total + powT[i][j]) % MOD;
            }
        }

        return static_cast<int>((total * 2) % MOD);
    }

private:
    vector<vector<long long>> matPow(vector<vector<long long>> base, long long exp) {
        int m = base.size();

        vector<vector<long long>> res(m, vector<long long>(m, 0));
        for (int i = 0; i < m; i++) {
            res[i][i] = 1;
        }

        while (exp > 0) {
            if (exp & 1) {
                res = mul(res, base);
            }
            base = mul(base, base);
            exp >>= 1;
        }

        return res;
    }

    vector<vector<long long>> mul(const vector<vector<long long>>& A,
                                  const vector<vector<long long>>& B) {
        int m = A.size();

        vector<vector<long long>> C(m, vector<long long>(m, 0));

        for (int i = 0; i < m; i++) {
            for (int k = 0; k < m; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < m; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }
};