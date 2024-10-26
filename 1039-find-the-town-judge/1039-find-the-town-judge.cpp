class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==0){
            return -1;
        }
        if(n==1){
            return 1;
        }
        vector<int> in(n+1,0);
        vector<int> out(n+1,0);

        for(auto pair:trust){
            out[pair[0]]++;
            in[pair[1]]++;
        }

        for(int i=0;i<min(in.size(),out.size());i++){
            if(i<in.size() && in[i]==n-1 && i<out.size() && out[i]==0){
                return i;
            }
        }
        return -1;
    }
};