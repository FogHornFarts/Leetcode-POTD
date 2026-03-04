class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int ans = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==1){
                    bool special = true;
                    for(int k=0;k<row;k++){
                        if(k!=i && mat[k][j]==1){
                            special = false;
                            break;
                        }
                    }
                    for(int k=0;k<col;k++){
                        if(k!=j && mat[i][k]==1){
                            special = false;
                            break;
                        }
                    }
                    if(special){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};