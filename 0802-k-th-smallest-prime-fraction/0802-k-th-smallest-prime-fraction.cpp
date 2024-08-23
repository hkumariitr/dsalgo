class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double div=0;
        vector<pair<double,pair<int,int>>> res;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                res.push_back({arr[i]*1.0/arr[j],{arr[i],arr[j]}});
            }
        }
        sort(res.begin(),res.end());

        auto mini = res[k-1];
        return {mini.second.first, mini.second.second};
    }
};