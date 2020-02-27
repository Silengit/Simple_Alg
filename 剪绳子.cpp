class Solution {
public:
    int cutRope(int number) {
        if(number == 2)
            return 1;
        if(number == 3)
            return 2;
        int max_num = 0;
        for(int i = 2; i <= number / 2; i++){
            int tmp = max(cutRope(number - i) * i, (number - i) * i);
            if(tmp > max_num)
                max_num = tmp;
        }
        return max_num;
    }
};