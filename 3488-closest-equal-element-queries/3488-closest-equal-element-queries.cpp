class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector <int> cnums;
        for(int i = 0; i <3; i++) {
            for(auto &i : nums) {
                cnums.push_back(i);
            }
        }
        int n = nums.size();
        vector <int> temp(3*n);
        unordered_map <int,int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
        for(int i = n; i < 2*n; i++) {
            temp[i]= i - mp[cnums[i]];
            mp[cnums[i]] = i;
        }
        mp.clear();
        for(int i = 3*n - 1; i >= 2*n; i--) {
            mp[cnums[i]] = i;
        }
        for(int i = 2*n - 1; i >= n; i--) {
            temp[i] = min(temp[i],mp[cnums[i]] - i);
            if(temp[i] == n) temp[i] = -1;
            mp[cnums[i]] = i;
        }
        vector <int> cnt;
        for(auto &i : queries) {
            cnt.push_back(temp[n+i]);
        }
        return cnt;
    }
};