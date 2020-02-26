class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size() == 0)
            return 0;
        MergeSort(data, 0, data.size()-1);
        return invert_n%1000000007;
    }
    
    void Merge(vector<int>& a, int l, int mid, int h) {
        int i = l, j = mid + 1, k = 0;
        int *new_a = new int[h - l + 1];
        while (i <= mid && j <= h) {
            if (a[i] < a[j])
                new_a[k++] = a[i++];
            else {
                new_a[k++] = a[j++];
                invert_n = (invert_n + mid + 1 - i)%1000000007;
            }
        }
        while (i <= mid)
            new_a[k++] = a[i++];
        while (j <= h)
            new_a[k++] = a[j++];
        for (int k = l; k <= h; k++)
            a[k] = new_a[k - l];
        delete []new_a;
    }

    void MergeSort(vector<int>& a, int l, int h) {
        if (l >= h)
            return;
        int mid = (h + l) / 2;
        MergeSort(a, l, mid);
        MergeSort(a, mid + 1, h);
        Merge(a, l, mid, h);
    }

    int invert_n = 0;
};