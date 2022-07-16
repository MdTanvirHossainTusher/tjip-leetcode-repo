// TC = O(N*M) where N * M = no of BLACK cell   
// MC = O(N*M)
class Solution {
public:
    vector<pair<int, int> > pos;
    int dirs[5] = {-1, 0, 1, 0, -1};
    int row, col;

    void traverse(int x, int y, vector<vector<char> > &image){
        image[x][y] = '0';
        pos.push_back({x - '0', y - '0'});
        for(int i = 0; i < 4; i++){
            int X = x + dirs[i];
            int Y = y + dirs[i + 1];
            if(X >= 0 && X < row && Y >= 0 && Y < col && image[X][Y] == '1'){
                traverse(X, Y, image);
            }
        }
    }
    int minArea(vector<vector<char>>& image, int px, int py) {
        pos.clear();
        row = image.size();
        col = image[0].size();
        traverse(px, py, image);
        int minRow = INT_MAX / 2, minCol = INT_MAX / 2;
        int maxRow = INT_MIN / 2, maxCol = INT_MIN / 2;

        for(auto p: pos){
            minRow = min(minRow, p.first);
            minCol = min(minCol, p.second);

            maxRow = max(maxRow, p.first);
            maxCol = max(maxCol, p.second);
        }
        int length = (maxRow - minRow) + 1;
        int width = (maxCol - minCol) + 1;
        return length * width;
    }
};
