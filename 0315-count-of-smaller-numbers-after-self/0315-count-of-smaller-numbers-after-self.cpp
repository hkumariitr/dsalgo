class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        vector<int> indices(n, 0);
        
        for (int i = 0; i < n; ++i) {
            indices[i] = i;
        }

        mergeSort(nums, indices, counts, 0, n - 1);
        return counts;
    }

private:
    void mergeSort(vector<int>& nums, vector<int>& indices, vector<int>& counts, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(nums, indices, counts, left, mid);
        mergeSort(nums, indices, counts, mid + 1, right);
        merge(nums, indices, counts, left, mid, right);
    }

    void merge(vector<int>& nums, vector<int>& indices, vector<int>& counts, int left, int mid, int right) {
        int l = left, r = mid + 1;
        vector<int> tempIndices(right - left + 1);
        int k = 0;

        while (l <= mid && r <= right) {
            if (nums[indices[l]] <= nums[indices[r]]) {
                tempIndices[k++] = indices[r++];
            } else {
                counts[indices[l]] += right - r + 1;
                tempIndices[k++] = indices[l++];
            }
        }

        while (l <= mid) {
            tempIndices[k++] = indices[l++];
        }

        while (r <= right) {
            tempIndices[k++] = indices[r++];
        }

        for (int i = left; i <= right; ++i) {
            indices[i] = tempIndices[i - left];
        }
    }
};
