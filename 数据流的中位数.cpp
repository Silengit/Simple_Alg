class Solution {
public:
    void Insert(int num)
    {
        int i = 0;
        if(arr.empty()){
            arr.push_back(num);
            return;
        }
        for(; i < arr.size(); i++)
            if(num < arr[i]){
                arr.insert(arr.begin() + i, num);
                break;
            }
        if(i == arr.size())
            arr.push_back(num);
    }

    double GetMedian()
    { 
        if(arr.size() % 2 == 1)
            return arr[(arr.size()-1)/2];
        else
            return double(arr[arr.size()/2-1]+arr[arr.size()/2])/2;
    }
    
    vector<int> arr;
};