class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if(k > input.size())
            return result;
        for(int i = 0; i < k; i++){
            Partial_Heap_Sort(input, 0);
            result.push_back(input[0]);
            input.erase(input.begin());
        }
        return result;
    }
    
    void Partial_Heap_Sort(vector<int> &a, int curIdx){
        if(curIdx < a.size()){
            Partial_Heap_Sort(a, curIdx * 2 + 1);
            Partial_Heap_Sort(a, curIdx * 2 + 2);
            int minIdx = curIdx;
            if(curIdx * 2 + 1 < a.size() && a[minIdx] > a[curIdx * 2 + 1])
                minIdx = curIdx * 2 + 1;
            if(curIdx * 2 + 2 < a.size() && a[minIdx] > a[curIdx * 2 + 2])
                minIdx = curIdx * 2 + 2;
            if(minIdx != curIdx)
                swap(a[minIdx], a[curIdx]);
        }
    }
};