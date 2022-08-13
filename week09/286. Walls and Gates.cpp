// TC = O(N)
// MC = O(N) where N is the total on of cells
class Solution {
public:
    void fillEmptyRoom(queue<pair<int,int> > &gates, vector<vector<int> > &rooms,int &row, int &col){
        int dirs[5] = {-1, 0, 1, 0, -1};

        while(!gates.empty()){
            pair<int,int> u = gates.front();
            gates.pop();
            int x = u.first;
            int y = u.second;
            for(int i = 0; i < 4; i++){
                int X = x + dirs[i];
                int Y = y + dirs[i + 1];
                if(X >= 0 && X < row && Y >= 0 && Y < col){
                    if(rooms[X][Y] > rooms[x][y] + 1){
                        rooms[X][Y] = rooms[x][y] + 1;
                        gates.push({X, Y});
                    }
                }
            }
        }
    }

    void wallsAndGates(vector<vector<int>>& rooms) {
        int row = rooms.size();
        int col = rooms[0].size();
        queue<pair<int,int> > gates;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(rooms[i][j] == 0){
                    gates.push({i, j});
                }
            }
        }
        fillEmptyRoom(gates, rooms, row, col);
        return;
    }
};
