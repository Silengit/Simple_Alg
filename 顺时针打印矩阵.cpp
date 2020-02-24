//hint: count how many circles int the matrix

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int circle = ((m < n ? m: n) + 1) / 2;
        vector<int> result;
        for(int i = 0; i < circle; i++){
            for(int j = i; j < n - i; j++)
                result.push_back(matrix[i][j]);
            for(int j = i+1; j < m - i && result.size() < m*n; j++)
                result.push_back(matrix[j][n-i-1]);
            for(int j = n-i-2; j >= i && result.size() < m*n; j--)
                result.push_back(matrix[m-i-1][j]);
            for(int j = m-i-2; j >= i+1 && result.size() < m*n; j--)
                result.push_back(matrix[j][i]);
        }
        return result;
    }
};