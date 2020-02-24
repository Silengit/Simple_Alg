#include <algorithm>
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> odd, even;
        for(auto& item: array){
            if(item % 2 == 1)
                odd.push_back(item);
            else
                even.push_back(item);
        }
        copy(odd.begin(), odd.end(), array.begin());
        copy(even.begin(), even.end(), array.begin()+odd.size());
    }
};