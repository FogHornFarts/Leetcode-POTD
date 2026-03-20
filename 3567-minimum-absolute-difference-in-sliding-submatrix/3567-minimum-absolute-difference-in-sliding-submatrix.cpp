class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n-k+1,vector<int>(m-k+1,0));
        for(int i=0;i<=n-k;i++){
            for(int j=0;j<=m-k;j++){
                set<int> st;
                for(int m=i;m<i+k;m++){
                    for(int n=j;n<j+k;n++){
                        st.insert(grid[m][n]);
                    }
                }
                int mini = INT_MAX;
                auto it = st.begin();
                auto prev = it;
                it++;
                while(it!=st.end()){
                    mini = min(mini, abs(*it-*prev));
                    prev = it;
                    it++;
                }
                ans[i][j] = (mini == INT_MAX ? 0 : mini);
            }
        }
        return ans;
    }
};