const int MAX_N = 1008;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        int sum = 0;
        memset(trace, 0, MAX_N * MAX_N * sizeof(bool));
        return walking(rows, cols, 0, 0, threshold);
    }
    
    int walking(int rows, int cols, int i, int j, int threshold){
        if(i < 0 || i >= rows || j < 0 || j >= cols) return 0;
        if(trace[i][j] == true || bitSum(i)+bitSum(j) > threshold) return 0;
        trace[i][j] = true;
        return walking(rows, cols, i-1, j, threshold) +
            walking(rows, cols, i+1, j, threshold) +
            walking(rows, cols, i, j-1, threshold) +
            walking(rows, cols, i, j+1, threshold) + 1;
    }
    
    int bitSum(int x){
        int sum = 0;
        while(x != 0){
            sum += x % 10;
            x = x/10;
        }
        return sum;
    }
    
    bool trace[MAX_N][MAX_N];
};