class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
            {
                vector<int> trace;
                if(helper(matrix, trace, rows, cols, i, j, str, 0) == true)
                    return true;
            }
        return false;
    }
    
    bool helper(char* matrix, vector<int> trace, int rows, int cols, int i, int j, char* str, int pos) {
        if (pos == strlen(str) - 1 && str[pos] == matrix[i * cols + j] && !hasItAlready(trace, i * cols + j))
            return true;
        else if (i < 0 || i >= rows || j < 0 || j >= cols)
            return false;
        else if (str[pos] == matrix[i * cols + j] && !hasItAlready(trace, i * cols + j)) {
            trace.push_back(i * cols + j);
            if(helper(matrix, trace, rows, cols, i - 1, j, str, pos + 1) ||
                helper(matrix, trace, rows, cols, i + 1, j, str, pos + 1) ||
                helper(matrix, trace, rows, cols, i, j - 1, str, pos + 1) ||
                helper(matrix, trace, rows, cols, i, j + 1, str, pos + 1))
                return true;
            trace.pop_back(); //No need indeed.
            return false;
        }
        else return false;
    }
   
    bool hasItAlready(vector<int> trace, int x){
        for(auto &item : trace)
            if(item == x)
                return true;
        return false;
    }
};