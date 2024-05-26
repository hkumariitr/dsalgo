class Solution {
public:
    int kthFactor(int n, int k) {
        int j = n/2;
        vector<int> ans;
        for(int i =j;i>=1;i--){
            if(n%i==0){
                ans.push_back(i);
            }
        }
        reverse(ans.begin(),ans.end());
        ans.push_back(n);
        for(auto i :ans){
            cout<< i << " ";

        }

        if(k>ans.size()){
            return -1;
        }
        return ans[k-1];
        

    }
};