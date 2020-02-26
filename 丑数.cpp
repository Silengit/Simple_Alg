//Hint: three queues
#include <vector>
#include <algorithm>

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index < 7)
            return index;
        vector<int> res;
        res.push_back(1);
        int h2 = 0, h3 = 0, h5 = 0;
        for (int i = 1; i < index; i++) {
            int min_ugly = min(min(res[h2] * 2, res[h3] * 3), res[h5] * 5);
            res.push_back(min_ugly);
            if(res[h2] * 2 == min_ugly) h2++;
            if(res[h3] * 3 == min_ugly) h3++;
            if(res[h5] * 5 == min_ugly) h5++;
        }
        return res[index - 1];
    }
};
