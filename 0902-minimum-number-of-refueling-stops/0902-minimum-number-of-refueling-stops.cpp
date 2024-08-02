class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> maxHeap;
        int fuel = startFuel;
        int pos = 0;
        int cnt = 0;
        int i = 0;
        int n = stations.size();
        
        while (fuel < target) {
            // Add all reachable stations to the maxHeap
            while (i < n && stations[i][0] <= fuel) {
                maxHeap.push(stations[i][1]);
                i++;
            }
            
            // If there are no more reachable stations and we haven't reached the target
            if (maxHeap.empty()) {
                return -1;
            }
            
            // Refuel with the largest available fuel amount
            fuel += maxHeap.top();
            maxHeap.pop();
            cnt++;
        }
        
        return cnt;
    }
};
