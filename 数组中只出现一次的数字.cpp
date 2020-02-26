#include <map>

class Solution {
public:
    void FindNumsAppearOnce(vector<int> &data, int* num1, int* num2) {
        map<int, int> dict;
        for (auto& item : data)
            dict[item] ++;
        int flag = 0;
        for (int i = 0; i < data.size(); i++)
            if (dict[data[i]] == 1) {
                if (flag++ == 0)
                    *num1 = data[i];
                else {
                    *num2 = data[i];
                    return;
                }
            }
    }
};