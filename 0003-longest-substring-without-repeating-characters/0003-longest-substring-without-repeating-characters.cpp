class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        int maxLen =0;
        unordered_map<char,int> mpp;
        int n = s.size();
        while(r<n){
            if (mpp.find(s[r]) != mpp.end()) {
                l = max(l, mpp[s[r]] + 1);
            }
            maxLen = max(maxLen, r - l + 1);
            mpp[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};