class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s, 0, s.size(), k);
    }

private:
    int helper(string &s, int start, int end, int k) {
        if (end - start < k) return 0;  // Base case: if the length is less than k, no valid substring
        int count[26] = {0};  // Frequency array for counting characters in the substring

        // Count frequency of each character in the substring [start, end)
        for (int i = start; i < end; i++) {
            count[s[i] - 'a']++;
        }

        // Check if any character occurs fewer than k times
        for (int i = start; i < end; i++) {
            if (count[s[i] - 'a'] < k) {  // Invalid character found
                int j = i + 1;
                while (j < end && count[s[j] - 'a'] < k) {
                    j++;  // Move past invalid characters
                }
                // Recursively find the longest valid substring
                return max(helper(s, start, i, k), helper(s, j, end, k));
            }
        }

        // If all characters occur at least k times, return the length of the substring
        return end - start;
    }
};
