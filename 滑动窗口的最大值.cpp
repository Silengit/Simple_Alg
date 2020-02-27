class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        if(size == 0)
            return res;
        if(size == 1)
            return num;
        if(size > num.size())
            return res;
        int max_num = 0;
        for(int i = 0; i < size; i++)
            if(num[i] > max_num)
                max_num = num[i];
        res.push_back(max_num);
        for(int i = 1; i < num.size() - size + 1; i++){
            if(num[i - 1] != max_num){
                max_num = max_num > num[i+size-1]? max_num: num[i+size-1];
                res.push_back(max_num);
            }
            else{        
                max_num = num[i];
                for(int j = i; j < i + size; j++)
                    if(num[j] > max_num)
                        max_num = num[j];
                res.push_back(max_num);
            }
        }
        return res;
    }
};