class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        unordered_map<int,int> diffCount;
        vector<int> oneDiff (k+1,0);
        int n = nums.size();
        for(int i =0;i<n/2;i++){
            int diff = abs(nums[i]-nums[n-1-i]);
            diffCount[diff]++;

            int maxi = max(nums[i],nums[n-1-i]);
            int mini = min(nums[i],nums[n-1-i]);
            int maxDiff = max(maxi-0,k-mini);

            oneDiff[maxDiff]++;
        }
        for(int j = k-1;j>=0;j--){
            oneDiff[j] += oneDiff[j+1];
        }
        int ans = INT_MAX;
        for(auto &[diff,count] : diffCount){
            int one = oneDiff[diff] - count;
            int two = n/2 - one - count ;

            ans = min(ans,one + two*2);

        }
        return ans;
    }
};