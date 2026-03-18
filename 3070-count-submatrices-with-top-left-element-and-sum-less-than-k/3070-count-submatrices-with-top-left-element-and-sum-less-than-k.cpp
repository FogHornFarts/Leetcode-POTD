class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ps(n, vector<int>(m, 0));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ps[i][j] = grid[i][j];

                if(i>0){
                    ps[i][j] += ps[i-1][j];
                }
                if(j>0){
                    ps[i][j] += ps[i][j-1];
                }
                if(i>0 && j>0){
                    ps[i][j] -= ps[i-1][j-1];
                }
                if(ps[i][j] <= k){
                    count++;
                }
            }
        }
        return count;
    }
};