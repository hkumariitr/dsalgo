class Solution {
public:
    // Function to compare two strings considering '#' as a backspace character.
    bool backspaceCompare(string s, string t) {
        // Initialize two pointers for the end of the strings.
        int sIndex = s.size() - 1, tIndex = t.size() - 1;
        // Initialize counters for the number of backspaces in s and t.
        int sSkip = 0, tSkip = 0;

        // While there are characters to compare in either string.
        while (sIndex >= 0 || tIndex >= 0) {
            // Find position of next possible character in s.
            while (sIndex >= 0) {
                if (s[sIndex] == '#') { // If a backspace char found, increment the skip counter.
                    ++sSkip;
                    --sIndex;
                } else if (sSkip > 0) { // If we have backspaces to apply, decrement the counter and index.
                    --sSkip;
                    --sIndex;
                } else {
                    break; // Found a valid character to compare.
                }
            }

            // Find position of next possible character in t.
            while (tIndex >= 0) {
                if (t[tIndex] == '#') { // If a backspace char found, increment the skip counter.
                    ++tSkip;
                    --tIndex;
                } else if (tSkip > 0) { // If we have backspaces to apply, decrement the counter and index.
                    --tSkip;
                    --tIndex;
                } else {
                    break; // Found a valid character to compare.
                }
            }

            // If both current indices are valid, compare the characters from s and t.
            if (sIndex >= 0 && tIndex >= 0) {
                // If the characters are different, return false.
                if (s[sIndex] != t[tIndex]) return false;
            } else if (sIndex >= 0 || tIndex >= 0) {
                // If one string has ended, but the other has not, they are not the same.
                return false;
            }

            // Move to the next character in each string.
            --sIndex;
            --tIndex;
        }

        // All compared characters are equal, return true.
        return true;
    }
};