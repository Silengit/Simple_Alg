class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        if (numbers.empty())
            return false;
        int kings = 0;
        for (int i = 0; i < numbers.size(); i++)
            if (numbers[i] == 0) {
                numbers.erase(numbers.begin() + i--);
                kings++;
            }
        if (numbers.empty())
            return true;
        sort(numbers.begin(), numbers.end());
        for (int i = 0; i < numbers.size() - 1; i++)
            if (numbers[i] != numbers[i + 1] - 1) {
                if (kings == 0)
                    return false;
                else {
                    numbers.insert(numbers.begin() + i + 1, numbers[i] + 1);
                    kings--;
                }
            }
        return true;
    }
};