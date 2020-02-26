class Solution {
public:
    int StrToInt(string str) {
        int flag = 0, i = 0, result = 0;
        if (str[0] == '+')
            i++;
        if (str[0] == '-') {
            i++;
            flag = 1;
        }
        for (; i < str.length(); i++) {
            if (str[i] - '0' >= 10 || str[i] - '0' < 0)
                return 0;
            else {
                int origin = result;
                result += (str[i] - '0') * pow(10, str.length() - i - 1);
                if (result - origin != (str[i] - '0') * pow(10, str.length() - i - 1)||
                    flag == 0 && result == 0x80000000)
                    return 0;
            }
        }
        return flag == 1 ? -result : result;
    }
};