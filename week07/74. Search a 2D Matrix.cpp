// TC = O(log(n*m)) where n = row, m = col
// MC = O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row, col;
        // cout<<"row : "<<matrix.size()<<" "<<"col : "<<matrix[0].size()<<endl;
        int L = 0, R = (matrix.size() * matrix[0].size()) - 1;
        while(L <= R){
            int M = L + (R - L) / 2;
            row = M / matrix[0].size();
            col = M % matrix[0].size();
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target){
                R = M - 1;
            }
            else{
                L = M + 1;
            }
        }
        return false;
    }
};
/**************************************/
// TC = O(log(n) + log(m)) where n = row, m = col
// MC = O(N)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        vector<int> val(row);
        for(int i = 0; i < row; i++){
            val[i] = matrix[i][0];
        }
        auto UB = upper_bound(val.begin(), val.end(), target) - val.begin();
        UB == 0? UB = 0 : UB = UB - 1;// [[1]], target = 0
        return binary_search(matrix[UB].begin(), matrix[UB].end(), target);
    }
};
/**************************************/
// TC = O(n + m) where n = row, m = col
// MC = O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int row = 0, col = cols - 1;
        // BST form kore like 7 er left a 5, right a 20..same for curr node 20,16 etc
        while(row < rows && col >= 0){
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) col--;
            else row++;
        }
        return false;
    }
};
