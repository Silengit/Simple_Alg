class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        if(sum == 0)
            return result;
        for(int i = 0; i <= array.size()/2; i++){
            int left = sum - array[i];
            if(BinSearch(array, left)){
                result.push_back(array[i]);
                result.push_back(left);
                return result;
            }
        }
        return result;
    }
    
    bool BinSearch(vector<int> array, int n){
        int lo = 0, hi = array.size() - 1;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(n == array[mid])
                return true;
            else if(n > array[mid])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return false;
    }
    
};