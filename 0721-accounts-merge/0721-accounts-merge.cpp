class DisjointSet {
    vector<int> rank;
    vector<int> parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<n;i++){
            parent[i] =i;
        }
    };

    int findUPar(int node){
        if (node ==parent[node]) return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionr(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        } else if( rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        // sort(accounts.begin(),accounts.end());
        unordered_map<string,int> mpp;
        set<string> st;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mpp.find(mail) == mpp.end()){
                    mpp[mail] =i;
                }else{
                    ds.unionr(i,mpp[mail]);
                }
            }
        }

        vector<vector<string>> mergedMail(n);
        for(auto it:mpp){
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i=0;i<n;i++){
            if(mergedMail[i].size()==0) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};