class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || k < 1) return -1; // Return -1 for invalid input

        // Min-heap using priority_queue
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;
        set<pair<int, int>> s;

        // Add the first element
        heap.push({matrix[0][0], 0, 0});
        s.insert({0, 0});

        while (k > 1) {
            vector<int> top = heap.top();
            heap.pop();
            int row = top[1];
            int col = top[2];

            // Add the next element in the row
            if (col + 1 < matrix[0].size() && s.find({row, col + 1}) == s.end()) {
                heap.push({matrix[row][col + 1], row, col + 1});
                s.insert({row, col + 1});
            }

            // Add the next element in the column
            if (row + 1 < matrix.size() && s.find({row + 1, col}) == s.end()) {
                heap.push({matrix[row + 1][col], row + 1, col});
                s.insert({row + 1, col});
            }

            k--;
        }

        return heap.top()[0];
    }
};
