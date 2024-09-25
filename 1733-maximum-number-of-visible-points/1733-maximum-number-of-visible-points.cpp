class Solution {
public:
    int visiblePoints(vector<std::vector<int>>& points, int angle, vector<int>& location) {
        vector<double> angles; // Vector to store the angles of the visible points
        int observer_x = location[0], observer_y = location[1]; // Observer's location
        int overlappingPoints = 0; // Count of points that overlap with the observer's location
        for (const auto& point : points) {
            int point_x = point[0], point_y = point[1];
            if (point_x == observer_x && point_y == observer_y) {
                // Increment count if the point's location is the same as the observer's location
                ++overlappingPoints;
            } else {
                // Calculate and store the angle from the observer to the point
                angles.push_back(atan2(static_cast<double>(point_y - observer_y),
                                       static_cast<double>(point_x - observer_x)));
            }
        }
      
        // Sort the angles in ascending order
        std::sort(angles.begin(), angles.end());
      
        int totalAngles = angles.size(); // Total number of unique angles
        // Duplicate the angles by appending 2*PI to each to handle the circular range
        for (int i = 0; i < totalAngles; ++i) {
            angles.push_back(angles[i] + 2 * M_PI);
        }

        int maxVisible = 0; // Maximum number of points visible within the angle
        double radianAngle = angle * M_PI / 180; // Convert angle to radians
      
        // Two-pointer approach to find the max number of points that fit within the angle
        for (int left = 0, right = 0; right < 2 * totalAngles; ++right) {
            // Move the left pointer until the points no longer fit in the viewing angle
            if(left < right && angles[right] - angles[left] > radianAngle) ++left;
            maxVisible = max(maxVisible, right - left + 1);
        }
      
        // Return the maximum number of points visible plus any overlapping points
        return maxVisible + overlappingPoints;
    }
};