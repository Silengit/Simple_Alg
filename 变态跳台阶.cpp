#include <numeric>
class Solution {
public:
    int jumpFloorII(int number) {
        if(number==0)
            return 0;
        else if(number==1)
            return 1;
        vector<int> steps;
        steps.push_back(0);
        steps.push_back(1);
        int result=steps[1];
        for(int i = 2; i <= number; i++){
            result = accumulate(steps.begin(),steps.end(),0)+1;
            steps.push_back(result);
        }
        return result;
    }
};