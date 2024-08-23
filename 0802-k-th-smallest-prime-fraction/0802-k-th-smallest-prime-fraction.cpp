class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double div=0;
        using pi = pair<double,pair<int,int>>;
        priority_queue<pi> pq;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                pq.push({arr[i]*1.0/arr[j],{arr[i],arr[j]}});
                if(pq.size()>k) pq.pop();
            }
        }
        auto mini = pq.top();
        return {mini.second.first, mini.second.second};
    }
};