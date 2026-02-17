class Solution {
public:
    int countBits(int x) {
        int cnt = 0;
        while (x) {
            cnt += (x & 1);
            x >>= 1;
        }
        return cnt;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (countBits(h) + countBits(m) == turnedOn) {
                    string t = to_string(h) + ":";
                    if (m < 10) t += "0";
                    t += to_string(m);
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
};
