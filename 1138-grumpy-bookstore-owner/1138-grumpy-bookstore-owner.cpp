class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int k = minutes;
        int n = customers.size();
        int l=0,r=0;
        int sum =0;
        for(int i=0;i<k;i++){
            if(grumpy[i]) sum +=customers[i];
        }
        r=k;
        int maxSum = sum;
        int left =0,right=0;
        while(r<n){
            if(grumpy[r]) sum+=customers[r];
            if(grumpy[l]) sum-=customers[l];
            if(sum>maxSum){
                left =l;
                right =r;
                maxSum = sum;
            }
            r++;
            l++;
        }
        sum=0;
        for(int i=0;i<n;i++){
            if(!grumpy[i]) sum += customers[i]; 
        }
        sum +=maxSum;
        return sum;
    }
};