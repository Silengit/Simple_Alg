class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int max_sum = array[0], sum = array[0];
        for(int i = 1; i < array.size(); i++){
            if(sum < 0)
                sum = array[i];
            else
                sum += array[i];
            if(sum > max_sum)
                max_sum = sum;
        }
        return max_sum;
    }
};