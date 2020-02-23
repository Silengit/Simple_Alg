class Solution {
public:
    void replaceSpace(char* str, int length) {
        int ctr = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ')
                ctr++;
        }
        if (ctr == 0)
            return;
        else {
            int j = length;
            while (j >= 0) {
                if (str[j] != ' ')
                    str[ctr * 2 + j] = str[j];
                else {
                    ctr--;
                    str[ctr * 2 + j] = '%';
                    str[ctr * 2 + j + 1] = '2';
                    str[ctr * 2 + j + 2] = '0';
                }
                j--;
            }
        }
    }
};