// TC = O(N) where N = total no of cell
// MC = O(1)
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        int battleShips = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){

                if(board[i][j] == '.') continue;

                if(i > 0 && board[i - 1][j] == 'X'){
                    continue;
                }
                if(j > 0 && board[i][j - 1] == 'X'){
                    continue;
                }
                battleShips++;
            }
        }
        return battleShips;
    }
};

/**********************************/
// TC = O(N) where N = total no of battle ships
// MC = O(1) no extra memory used, but value changed
class Solution {
public:
    int dirs[5] = {-1, 0, 1, 0, -1};

    void traverse(int x, int y, vector<vector<char> > &board, int &row, int &col){
        board[x][y] = '.';
        for(int i = 0; i < 4; i++){
            int X = x + dirs[i];
            int Y = y + dirs[i + 1];
            if(X >= 0 && X < row && Y >= 0 && Y < col && board[X][Y] == 'X'){
                traverse(X, Y, board, row, col);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        int battleShips = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'X'){
                    battleShips++;
                    traverse(i, j, board, row, col);
                }
            }
        }
        return battleShips;
    }
};
