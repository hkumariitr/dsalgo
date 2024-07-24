class Solution {
public:
    int countLessEqual(vector<vector<int>>& matrix, int x) {
        int count = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        for (int i = 0; i < n; ++i) {
            int left = 0, right = m - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (matrix[i][mid] <= x) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            count += left; // Number of elements <= x in row i
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = matrix[0][0];
        int high = matrix[n - 1][m - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (countLessEqual(matrix, mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};
