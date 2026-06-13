class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;
        for(int i=0;i<words.size();i++){
            int sum = 0;
            for(char c: words[i]){
                sum+=weights[c-'a'];
            }
            int res_num = sum % 26;
            result += 'z' - res_num;
        }
        return result;
    }
};