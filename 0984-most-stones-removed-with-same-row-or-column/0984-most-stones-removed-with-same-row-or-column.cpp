class Dsu{
    vector<int> parent;
    vector<int> rank;
    
public:
    Dsu(int n){
            parent.resize(n+1);
            rank.resize(n+1,0);
    
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
    int findPar(int node){
        if(parent[node] == node){
            return parent[node];    
        }
        return parent[node] = findPar(parent[node]);
        
    }
    void unionRank(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if(ulp_u == ulp_v) return ;
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        } else if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for(auto it:stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }

        Dsu ds(maxRow + maxCol + 1);
        unordered_map<int,int> nodestones;
        for(auto it:stones){
            int noderow = it[0];
            int nodecol = it[1] + maxRow+1;
            ds.unionRank(noderow, nodecol);

            nodestones[noderow] =1;
            nodestones[nodecol]=1;
        }
        int cnt =0;
        for (auto it :nodestones){
            if(ds.findPar(it.first)==it.first){
                cnt++;
            }
        }
        return n - cnt;
    }
};