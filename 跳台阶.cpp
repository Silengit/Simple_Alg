class Solution {
public:
    int jumpFloor(int number) {
        if(number==0)
            return 0;
        else if(number==1)
            return 1;
        else{
            int a = 1, b = 1, result;
            for(int i = 2;i<=number;i++){
                result = a+b;
                a=b;
                b=result;
            }
            return result;
        }
    }
};