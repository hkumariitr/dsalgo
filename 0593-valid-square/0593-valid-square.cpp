class Solution {
public:
    int distance(int x1,int x2, int y1, int y2){
        return pow((x1-x2),2) + pow((y1-y2),2);
    }
    bool solve (vector<int>& p1, vector<int>& p2, vector<int>& p3){
        int d1 = distance(p1[0],p2[0],p1[1],p2[1]);
        int d2 = distance(p2[0],p3[0],p2[1],p3[1]);
        int d3 = distance(p3[0],p1[0],p3[1],p1[1]);
        if(d1==0|| d2==0|| d3==0) return false;
        if(d1 == d2 && (d1 +d2) ==d3 ) return true;
        if(d2 == d3 && (d2 +d3) ==d1 ) return true;
        if(d3 == d1 && (d3 +d1) ==d2 ) return true;

        return false;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return solve(p1,p2,p3) && solve(p2,p3,p4) && solve(p3,p4,p1) && solve(p4,p1,p2);
    }
};