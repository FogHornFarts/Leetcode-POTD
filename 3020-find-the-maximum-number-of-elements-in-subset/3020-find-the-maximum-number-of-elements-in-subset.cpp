class Solution {
public:
    long long power(int num , int k){
        if(k == 1){
            return num;
        }

        long long cur = power(num , k/2);
        cur *= cur;

        if(k % 2) cur *= num;
        return cur;
    }
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
        }

        int ans = 1;
        for(pair<int,int> it : mp){
            int num = it.first;
            int cnt = it.second;

            if(num == 1){
                if(cnt%2){
                    ans = max(ans , cnt);
                }
                else ans = max(ans , cnt-1);

                continue;
            }

            if(cnt >= 2){
                int cnt = 0;
                for(int k = 0 ; k < 5 ; k++){
                    long long number = power(num , 1<<k);
                    if(number > 1e9) break;
                    
                    if(mp.count((int)number) && mp[(int)number] >= 2){
                        cnt++;
                    }
                    else if(mp.count((int)number) && mp[(int)number] == 1){
                        cnt++;
                        break;
                    }
                    else break;
                }

                ans = max(ans , cnt*2-1);
            }
        }
        return ans;
    }
};