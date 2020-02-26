class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> result;
        if(sum == 0)
            return result;
        for(int i = 2; i <= sum/2 + 1; i++){
            if(sum % i == 0 && i % 2 == 1 && sum / i - i / 2 >= 1){
                vector<int> tmp;
                for(int j = sum / i - i / 2; j <= sum / i + i / 2; j++)
                    tmp.push_back(j);
                result.insert(result.begin(), tmp);
            }
            else if(sum % i == i / 2 && i % 2 == 0 && sum / i - i / 2 + 1>= 1){
                vector<int> tmp;
                for(int j = sum / i - i / 2 + 1; j <= sum / i + i / 2; j++)
                    tmp.push_back(j);
                result.insert(result.begin(), tmp);
            }
        }
        return result;
    }
};