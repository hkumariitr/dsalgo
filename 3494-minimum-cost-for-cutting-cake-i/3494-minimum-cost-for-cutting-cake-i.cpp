class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(),horizontalCut.end());
        reverse(horizontalCut.begin(),horizontalCut.end());

        sort(verticalCut.begin(),verticalCut.end());
        reverse(verticalCut.begin(),verticalCut.end());

        int verticalPieces = 1;
        int horizontalPieces = 1;

        int cost = 0;

        int i=0,j=0;

        while(i<m-1 && j<n-1){
            if(horizontalCut[i]>verticalCut[j]){
                cost += horizontalCut[i]*verticalPieces;
                horizontalPieces++;
                i++;
            }else{
                cost += verticalCut[j]*horizontalPieces;
                verticalPieces++;
                j++;                
            }
        }

        while(i<m-1){
            cost += horizontalCut[i]*verticalPieces;
                horizontalPieces++;
                i++;
        }
        while(j<n-1){
            cost += verticalCut[j]*horizontalPieces;
                verticalPieces++;
                j++;
        }

        return cost;
    }
};