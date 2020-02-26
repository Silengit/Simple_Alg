#include <algorithm>

class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str.begin(), str.end());
        int i = 0, j = 0;
        while(j < str.length()){
            if(str[j] != ' ' && j != str.length() - 1)
                j++;
            else{
                if(j == str.length() - 1)
                   j++;
                reverse(str.begin() + i, str.begin() + j);
                i = ++j;
            }
        }
        return str;
    }
};