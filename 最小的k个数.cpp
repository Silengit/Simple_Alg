#include <algorithm>
#include <string>

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), lessThan);
        string res;
        for(auto &item : numbers)
            res += to_string(item);
        return res;
    }
    
    static bool lessThan(int a, int b){
        return stoi(to_string(a) + to_string(b)) < stoi(to_string(b) + to_string(a));
    }
};