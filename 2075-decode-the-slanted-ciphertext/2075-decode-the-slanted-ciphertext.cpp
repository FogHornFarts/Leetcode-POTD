class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int col = n/rows;
        vector<vector<char>> matrix(rows, vector<char>(col));
        int k = 0;
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<col; j++){
                matrix[i][j] = encodedText[k++];
            }
        }
        string ans = "";
        for(int startCol = 0; startCol<col; startCol++){
            int i = 0, j = startCol;
            while(i < rows && j < col){
                ans.push_back(matrix[i][j]);
                i++;
                j++;
            }
        }
        while(!ans.empty() && ans.back() == ' '){
            ans.pop_back();
        }
        return ans;
    }
};