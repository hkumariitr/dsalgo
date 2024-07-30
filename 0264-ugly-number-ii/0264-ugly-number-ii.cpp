class Solution {
public:
    int nthUglyNumber(int n) {
         // Min-heap (priority queue)
    priority_queue<long, vector<long>, greater<long>> pq;
    // Set to avoid duplicates
    unordered_set<long> seen;

    // Initial ugly number is 1
    pq.push(1);
    seen.insert(1);

    // Factors for generating ugly numbers
    int factors[3] = {2, 3, 5};

    long ugly = 1;

    for (int i = 0; i < n; ++i) {
        ugly = pq.top();
        pq.pop();

        // Generate the next ugly numbers and add to the heap if not seen
        for (int factor : factors) {
            long nextUgly = ugly * factor;
            if (seen.find(nextUgly) == seen.end()) {
                pq.push(nextUgly);
                seen.insert(nextUgly);
            }
        }
    }

    return ugly;
    }
};