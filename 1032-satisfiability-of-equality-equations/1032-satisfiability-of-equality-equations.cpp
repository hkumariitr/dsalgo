class Dsu{
    vector<int> rank;
    vector<int> parent;
public:
    Dsu(){
        rank.resize(26,1);
        parent.resize(26);
        for(int i=0;i<26;i++){
            parent[i] = i;
        }
    }

    int findPar(int node){
        if(parent[node] ==node) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionRank(int u, int v){
        int ulp_u = parent[u];
        int ulp_v = parent[v];

        if(ulp_u == ulp_v) return ;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }

    }

};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        Dsu *ds = new Dsu();
        for(auto eq:equations){
            char a = eq[0];
            char b = eq[3];
            char sym = eq[1];

            if(sym == '='){
                ds->unionRank((a-'a'),(b-'a'));
            }
        }
        for(auto eq:equations){
            char a = eq[0];
            char b = eq[3];
            char sym = eq[1];

            if(sym == '!'){
                int ulp_a = ds->findPar(a-'a');
                int ulp_b = ds->findPar(b-'a');

                if(ulp_a == ulp_b) return false;
            }
        }
        return true;
    }
};