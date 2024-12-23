class DisjointSet {
    vector<int> rank, parent, size;
    
public:
    int count =0;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) {
            count++;
            return;
        }
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int dots  =grid.size()+1;
        DisjointSet ds(dots*dots);

        for(int i=0;i<dots;i++){
            for(int j=0;j<dots;j++){
                if(i==0 || j==0 || i== dots-1 || j== dots-1){
                    int cellno = i*dots+j;
                    ds.unionByRank(0,cellno);

                }
            }
        }

        for(int i=0;i<grid.size();i++){
            string str = grid[i];
            vector<char> ch(str.begin(), str.end());
            ch.push_back('\0');
            for(int j= 0;j<ch.size();j++){
                if(ch[j] == '/'){
                    int cellno1 = i*dots + j+1;
                    int cellno2 = (i+1)*dots + j;
                    ds.unionByRank(cellno1,cellno2);
                }else if(ch[j]=='\\'){
                    int cellno1 = i*dots + j;
                    int cellno2 = (i+1)*dots + j+1;
                    ds.unionByRank(cellno1,cellno2);
                }
            }
        }
        return ds.count;

        
        
    }
};