class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum=0,rsum=0,maxSum=0;
        for(int i =0;i<k;i++){
            lsum +=cardPoints[i];
        }

        maxSum = lsum;

        for(int i=k-1;i>=0;i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[i+n-k];

            maxSum = max(maxSum,lsum+rsum);
        }
        return maxSum;
    }
};