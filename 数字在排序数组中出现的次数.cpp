class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty())
            return 0;
        int i = 0, ctr = 0; 
        for(;  i < data.size() && data[i] != k; i++);
        if(i == data.size() && data[i-1] != k)
            return 0;
        for(;  i < data.size() && data[i] == k; i++)
            ctr++;
        return ctr;
    }
};