class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int up = 0, right = array[0].size() - 1;
        while (up < array.size() && right >= 0) {
            if (target == array[up][right])
                return true;
            else if (target > array[up][right])
                up++;
            else
                right--;
        }
        return false;
    }
};