class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        if (data.empty())
            return 0;
        return BinSearch(data, k + 0.5) - BinSearch(data, k - 0.5);
    }

    int BinSearch(vector<int> data, double x) {
        int lo = 0, hi = data.size() - 1;
        int mid;
        while (hi >= lo) {
            mid = (lo + hi) / 2;
            if (data[mid] > x)
                hi = mid - 1;
            else if (data[mid] < x)
                lo = mid + 1;
            else
                return mid;
        }
        return lo;
    }
};