class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,r=0;
        int n =nums.size();
        while(r<n){
            if(nums[l]>nums[r]){
                swap(nums[l],nums[r]);
                int temp = l;
                while(l>0 && nums[l-1]>nums[l]){
                    swap(nums[l-1],nums[l]);
                    l--;
                }
                l=temp+1;                
            }
            if(r>0 && nums[r-1]>nums[r]){
                swap(nums[r-1],nums[r]);      
            }
            
            r++;
        }
    }
};