class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.rbegin(),horizontalCut.rend());
        
        sort(verticalCut.rbegin(),verticalCut.rend());
       

        int verticalPieces = 1;
        int horizontalPieces = 1;

        long long cost = 0;

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