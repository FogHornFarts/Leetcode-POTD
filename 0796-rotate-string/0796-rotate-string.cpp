class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()){
            return false;
        }
        for (int i = 0;i<s.length();i++) {
            if (s == goal){
                return true;
            }
            char first = s[0];
            s = s.substr(1) + first;
        }
        return false;
    }
};