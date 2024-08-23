class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int cnt=0;
        pair<double,pair<int,int>> mini;
        using pi = pair<double,pair<int,int>>;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        int n = arr.size();
        for(int j=n-1;j>=0;j--){
            for(int i=0;i<j;i++){
                double ans = (arr[i]*1.0)/arr[j];
                pq.push({ans,{i,j}});
            }
            mini = pq.top();
            cnt++;
            pq.pop();
            if(cnt==k) break;
        }
        while(cnt!=k){
            mini = pq.top();
            cnt++;
            pq.pop();
        }
        return {arr[mini.second.first], arr[mini.second.second]};
    }
};