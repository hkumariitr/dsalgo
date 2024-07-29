class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        int rem = nums.size()-k;
        for(auto a:nums){
            while(!ans.empty() && rem && a<ans.back()){
                ans.pop_back();
                rem--;
            }
            ans.push_back(a);
        }
        while(rem){
            rem--;
            ans.pop_back();
        }
        return ans;
    }
};