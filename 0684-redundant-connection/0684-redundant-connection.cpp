class Solution {
private:
    int findparent(vector<int>& parent,int node){
        if(parent[node]==node) return node;
        return parent[node]=findparent(parent,parent[node]);
    }
    void unionset(int u,int v,vector<int>& parent,vector<int>& rank){
        u=findparent(parent,u);
        v=findparent(parent,v);
        if(rank[u]<rank[v]){
            parent[u]=v;
        }else if(rank[v]<rank[u]){
            parent[v]=u;
        }else{
            parent[u]=v;
            rank[v]++;
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n+1);
        vector<int>rank(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            if(findparent(parent,u)==findparent(parent,v)){
                return {u,v};
            }
            unionset(u,v,parent,rank);
        }
        return {};
    }
};