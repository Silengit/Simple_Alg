class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int winner = numbers[0];
        int points = 0;
        for(int i = 0; i < numbers.size(); i += 2){
            if(numbers[i] == numbers[i+1]){
                if(numbers[i] == winner)
                    points++;
                else{
                    points--;
                    if(points < 0){
                        points = 1;
                        winner = numbers[i];
                    }
                }
            }
        }
        int ctr = 0;
        for(int i = 0; i < numbers.size(); i++)
            if(numbers[i] == winner)
                ctr++;
        if(ctr*2 > numbers.size())
            return winner;
        else return 0;
    }
};