class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s = "123456789";
        
        int lowLen = to_string(low).length();
        int highLen = to_string(high).length();
        for(int len = lowLen;len<=highLen;len++){
            for(int i=0;i+len<=9;i++){
                string temp = s.substr(i, len);
                int num = stoi(temp);
                if(num>=low && num<=high){
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};

