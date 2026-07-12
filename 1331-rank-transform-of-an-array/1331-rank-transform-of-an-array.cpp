class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy = arr;
        sort(copy.begin(), copy.end());
        copy.erase(unique(copy.begin(), copy.end()), copy.end());
        for(int i=0;i<arr.size();i++){
            arr[i] = lower_bound(copy.begin(), copy.end(), arr[i]) - copy.begin() + 1;
        }
        return arr;
    }
};