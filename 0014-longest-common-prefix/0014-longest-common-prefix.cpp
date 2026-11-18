class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs.back();
        string res = "";
        
        for (int i = 0; i < first.size(); i++) {
            if (i < last.size() && first[i] == last[i]) {
                res += first[i];
            } else {
                break;
            }
        }
        return res;
    }
};
