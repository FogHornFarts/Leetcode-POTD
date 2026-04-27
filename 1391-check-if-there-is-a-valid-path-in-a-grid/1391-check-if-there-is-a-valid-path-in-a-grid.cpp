class Solution {
public:
    int row, col, m, n, newOut;
    vector<vector<int>> visited;
    
    // Left Right Up Down
    vector<vector<int>> table = {
        {0, 0, 0, 0}, 
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {1, 0, 0, 1},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 1, 0} 
    };
    
    bool checkOut(int r, int c, int prevOut, vector<vector<int>>& grid) {
        int street = grid[r][c];
        int entryHole;
        
        if (prevOut == 0) entryHole = 1;      
        else if (prevOut == 1) entryHole = 0; 
        else if (prevOut == 2) entryHole = 3; 
        else entryHole = 2;                  

        if (table[street][entryHole] == 0) return false;

        for (int i = 0; i < 4; i++) {
            if (i == entryHole) continue;
            if (table[street][i] == 1) {
                newOut = i;
                return true;
            }
        }
        return (r == m - 1 && c == n - 1);
    }

    bool checkIn(int r, int c, int out) {
        row = r; col = c;
        if (out == 0) col = c - 1;      
        else if (out == 1) col = c + 1;
        else if (out == 2) row = r - 1;
        else if (out == 3) row = r + 1;

        return (row >= 0 && row < m && col >= 0 && col < n && visited[row][col] != 1);
    }

    bool path(int r, int c, int out, vector<vector<int>>& grid) {
        visited[r][c] = 1;
        if (r == m - 1 && c == n - 1) return true;

        if (!checkIn(r, c, out)) return false;
        if (!checkOut(row, col, out, grid)) return false;

        return path(row, col, newOut, grid);
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        int street = grid[0][0];
        visited.assign(m, vector<int>(n, 0));

        if (street == 1) return path(0, 0, 1, grid);
        if (street == 2) return path(0, 0, 3, grid);
        if (street == 3) return path(0, 0, 3, grid);
        if (street == 4) {
            if (path(0, 0, 3, grid)) return true;
            visited.assign(m, vector<int>(n, 0));
            return path(0, 0, 1, grid);
        }
        if (street == 6) return path(0, 0, 1, grid);
        
        return false;
    }
};