class Solution {
public:
    bool dfs(int r, int c, vector<vector<int>>& grid, int ROWS, int COLS) {
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS) return false;
        if (grid[r][c] == 1) return true;
        grid[r][c]=1;
        bool down = dfs(r + 1, c, grid, ROWS, COLS);
        bool up = dfs(r - 1, c, grid, ROWS, COLS);
        bool right = dfs(r, c + 1, grid, ROWS, COLS);
        bool left = dfs(r, c - 1, grid, ROWS, COLS);
        return down && up && right && left;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        set<pair<int, int>> visit;

        int res = 0;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == 0) {
                    if (dfs(r, c, grid, ROWS, COLS)) {
                        res += 1;
                    }
                }
            }
        }

        return res;
    }
};