class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (strlen(str) == 0 && strlen(pattern) == 0)
            return true;
        unsigned i = 0, j = 0;
        return RecHelper(str, pattern, 0, 0);
    }
    
    bool RecHelper(char* str, char* pattern, unsigned i, unsigned j){
        if(i > strlen(str) || j > strlen(pattern))
            return false;
        else if(i == strlen(str) && j == strlen(pattern))
            return true;
        else{
            if((j < strlen(pattern) - 1 && pattern[j+1] != '*') || 
               j == strlen(pattern) - 1){
                if(str[i] == pattern[j] || pattern[j] == '.')
                    return RecHelper(str, pattern, i + 1, j + 1);
                else return false;
            }
            else{
                if(str[i] != pattern[j] && pattern[j] != '.')
                    return RecHelper(str, pattern, i, j + 2);
                else return RecHelper(str, pattern, i, j + 2)||
                    RecHelper(str, pattern, i + 1, j);
            }
        }
    }
};