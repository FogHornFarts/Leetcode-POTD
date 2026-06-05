class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;
    Node dp[20][2][3][11][11];
    bool vis[20][2][3][11][11];

    static int isWave(int left, int mid, int right) {
        return ((mid > left && mid > right) ||
                (mid < left && mid < right)) ? 1 : 0;
    }

    Node dfs(int pos, bool tight, bool started,
             int lenState, int last1, int last2) {

        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][started][lenState][last1][last2]) {
            return dp[pos][started][lenState][last1][last2];
        }

        int limit = tight ? (s[pos] - '0') : 9;

        long long totalCnt = 0;
        long long totalWav = 0;

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, ntight, false, 0, 10, 10);

                totalCnt += nxt.cnt;
                totalWav += nxt.wav;
            } else {
                if (!started) {
                    Node nxt = dfs(pos + 1, ntight, true, 1, d, 10);

                    totalCnt += nxt.cnt;
                    totalWav += nxt.wav;
                }
                else if (lenState == 1) {
                    Node nxt = dfs(pos + 1, ntight, true, 2, d, last1);

                    totalCnt += nxt.cnt;
                    totalWav += nxt.wav;
                }
                else { 
                    int add = isWave(last2, last1, d);

                    Node nxt = dfs(pos + 1, ntight, true, 2, d, last1);

                    totalCnt += nxt.cnt;
                    totalWav += nxt.wav + nxt.cnt * 1LL * add;
                }
            }
        }
        Node res = {totalCnt, totalWav};
        if (!tight) {
            vis[pos][started][lenState][last1][last2] = true;
            dp[pos][started][lenState][last1][last2] = res;
        }
        return res;
    }
    long long solve(long long N) {
        if (N < 0) return 0;
        s = to_string(N);
        memset(vis, 0, sizeof(vis));
        return dfs(0, true, false, 0, 10, 10).wav;
    }
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};