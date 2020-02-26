#include <map>

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char, int> dict;
        if(str.length() == 0)
            return -1;
        for(int i = 0; i < str.length(); i++){
            if(dict.find(str[i]) == dict.end())
                dict[str[i]] = 1;
            else
                dict[str[i]] ++;
        }
        for(int i = 0; i < str.length(); i++)
            if(dict[str[i]] == 1)
                return i;
        return -1;
    }
};