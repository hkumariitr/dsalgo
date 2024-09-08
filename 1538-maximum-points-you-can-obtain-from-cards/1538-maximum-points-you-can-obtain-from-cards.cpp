class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int score =0;
        for(int i =0;i<k;i++){
            score += cardPoints[i];
        }
        int maxScore = score;
        int r = n-1;
        int i = k-1;
        while(i>=0){
           score -=cardPoints[i];
           score += cardPoints[r];
           maxScore = max(maxScore,score);
           r--;
           i--;
        }
        return maxScore;
    }
};