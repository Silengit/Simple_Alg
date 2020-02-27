class Solution {
public:
    bool isNumeric(char* string)
    {
        if (strlen(string) == 0)
            return false;
        int i = 0, j = 0, dot = 0, power = 0, power_flag = 0;
        if (string[i] == '+' || string[i] == '-')
            i++;
        for (j = i; j < strlen(string); j++) {
            if (power == 0) {
                if (dot > 1)
                    return false;
                if (string[j] - '0' >= 0 && string[j] - '0' <= 9)
                    continue;
                else if (string[j] == '.') {
                    dot++;
                }
                else if (string[j] == 'e' || (string[j] == 'E'))
                    power++;
                else return false;
            }
            else if (power == 1) {
                if (string[j] == '+' || string[j] == '-') {
                    if (power_flag == 0)
                        power_flag = 1;
                    else return false;
                }
                else if (string[j] == '.')
                    return false;
                else if (string[j] - '0' >= 0 && string[j] - '0' <= 9)
                    continue;
                else
                    return false;
            }
            else
                return false;
        }
        if (string[j - 1] == 'e' || string[j - 1] == 'E')
            return false;
        return true;
    }
};