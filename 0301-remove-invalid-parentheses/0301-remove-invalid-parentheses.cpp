class Solution {
    vector<set<string>> valid;
    int mn = 30;
    void go(int i, int val, int rmv, string t, string &s){
        if(val<0 || val>s.size()-i || rmv>mn){
            return;
        }
        if(i==s.size()){
            if(val==0){
                mn = min(mn, rmv);
                valid[rmv].insert(t);
            }
            return;
        }
        go(i+1, val, rmv+1, t, s);
        if(s[i] == '('){
            val++;
        }
        if(s[i] == ')'){
            val--;
        }
        t+=s[i];
        go(i+1, val, rmv, t, s);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        valid = vector<set<string>> (s.size()+1);
        go(0, 0, 0, "", s);
        for(auto &it : valid){
            if(it.size()){
                return vector<string> (it.begin(), it.end());
            }
        }
        return vector<string>();
    }
};