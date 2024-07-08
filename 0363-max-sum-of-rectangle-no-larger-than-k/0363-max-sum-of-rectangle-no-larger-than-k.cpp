class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int r = matrix.size();
        int c = matrix[0].size();
        int maxSum = INT_MIN;
        
        for (int left = 0; left < c; ++left) {
            vector<int> csum(r, 0);
            for (int right = left; right < c; ++right) {
                for (int i = 0; i < r; ++i) {
                    csum[i] += matrix[i][right];
                }
                
                set<int> sums;
                sums.insert(0);
                int currSum = 0;
                for (int sum : csum) {
                    currSum += sum;
                    auto it = sums.lower_bound(currSum - k);
                    if (it != sums.end()) {
                        maxSum = max(maxSum, currSum - *it);
                    }
                    sums.insert(currSum);
                }
            }
        }
        
        return maxSum;
    }
};