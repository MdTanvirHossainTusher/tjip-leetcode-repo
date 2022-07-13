// TC = O(N) where N = total no of cells in the grid
// MC = O(1)
class Solution {
public:
    static const char VISITED = '2';
    static const char UNVISITED = '1';
    static constexpr int dirs[5] = {-1, 0, 1, 0, -1};
    int row, col;

    void traverse(int x, int y, vector<vector<char> > &grid){
        grid[x][y] = VISITED;
        for(int i = 0; i < 4; i++){
            int X = x + dirs[i];
            int Y = y + dirs[i + 1];
            if(X >= 0 && X < row && Y >= 0 && Y < col && grid[X][Y] == UNVISITED){
                traverse(X, Y, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int totalIsland = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == UNVISITED){
                    totalIsland++;
                    traverse(i, j, grid);
                }
            }
        }
        return totalIsland;
    }
};
