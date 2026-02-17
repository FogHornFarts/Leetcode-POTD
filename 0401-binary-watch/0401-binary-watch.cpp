class Solution {
public:
    
    int countBits(int x) {
        int cnt = 0;
        while (x) {
            cnt += (x & 1);   // check last bit
            x >>= 1;          // right shift
        }
        return cnt;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {

                if (countBits(h) + countBits(m) == turnedOn) {
                    string time = to_string(h) + ":";

                    if (m < 10) time += "0";   // minute must be 2 digits
                    time += to_string(m);

                    ans.push_back(time);
                }
            }
        }

        return ans;
    }
};
