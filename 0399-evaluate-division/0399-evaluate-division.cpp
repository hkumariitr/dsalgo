class Solution {
public:
    void dfs(string start, string end, unordered_map<string, vector<pair<string,double>>> &mpp,double &ans, double pr,unordered_set<string> &visited ){
        
        if(visited.find(start)!=visited.end()) {return;}

        visited.insert(start);

        if(start == end){
            ans = pr;
            return;
        }

        for(auto &[next,value]:mpp[start]){
            dfs(next,end,mpp,ans,pr*value,visited);
        }

    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>> mpp;

        for(int i=0;i<equations.size();i++){
            vector<string> eq = equations[i];
            double val = values[i];
            mpp[eq[0]].push_back({eq[1],val});
            mpp[eq[1]].push_back({eq[0],(1.0/val)});
        }

        vector<double> result;

        for(int i=0;i<queries.size();i++){
            string start = queries[i][0];
            string end = queries[i][1];

            double ans = -1.0;
            double pr = 1.0;

            if(mpp.find(start)!=mpp.end()){
                unordered_set<string> visited;
                dfs(start,end,mpp,ans,pr,visited);
            }

            result.push_back(ans);
        }
        return result;
    }
};