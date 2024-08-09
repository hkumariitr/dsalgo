class Solution {
public:
    int check(int n){
        int c =0;
        for(int i=2;i<n;i++){
            if(n%i==0) c++;
            if(c>1) break;                       
        }
        return (c!=1)? 1 :0;
    }
    int nonSpecialCount(int l, int r) {
        int cnt =0;
        for(int i=l;i<=r;i++){
            cnt += check(i);
        }
        return cnt;
    }
};