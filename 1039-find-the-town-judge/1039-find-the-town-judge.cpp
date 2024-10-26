class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> out(n+1);
        vector<vector<int>> in(n+1);
        for(auto person:trust){
            out[person[0]].push_back(person[1]);
            in[person[1]].push_back(person[0]);
        }
        for(int i = 1;i<=n;i++){
            if(out[i].empty() && in[i].size()==n-1){
                return i;
            }
        }
        return -1;
    }
};