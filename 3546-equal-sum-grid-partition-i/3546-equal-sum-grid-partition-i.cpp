class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        long long total = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                total+=grid[i][j];
            }
        }
        if(total%2 != 0){
            return false;
        }
        long long target = total/2;
        long long sum = 0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                    sum+=grid[i][j];
            }
            if(sum==target){
                return true;
            }
        }
        sum = 0;
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n;j++){
                sum+=grid[j][i];
            }
            if(sum==target){
                return true;
            }
        }
        return false;
    }
};