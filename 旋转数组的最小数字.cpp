Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0)
            return 0;
        else if (rotateArray.size() == 1)
            return rotateArray[0];
        int mid = (rotateArray.size() - 1) / 2;
        if (rotateArray[mid] > rotateArray[rotateArray.size() - 1]) {
            vector<int> newArray(5);
            newArray.assign(rotateArray.begin() + mid + 1, rotateArray.end());
            return minNumberInRotateArray(newArray);
        }
        else {
            vector<int> newArray;
            newArray.assign(rotateArray.begin(), rotateArray.begin() + mid+1);
            return minNumberInRotateArray(newArray);
        }
    }
};