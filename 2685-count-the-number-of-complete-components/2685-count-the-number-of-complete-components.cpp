class Solution {
private:
    void dfs(int node,vector<int>& visited,vector<int>& component,vector<vector<int>>& adj){
        visited[node]=1;
        component.push_back(node);
        for(auto num : adj[node]){
            if(!visited[num]){
                dfs(num,visited,component,adj);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto e : edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(n,0);
        vector<vector<int>>components;
        for(int i=0;i<n;i++){
            vector<int>component;
            if(!visited[i]){
                dfs(i,visited,component,adj);
                components.push_back(component);
            }
        }
        int count=0;
        for (auto component : components) {
            int vertices = component.size();
            int edges = 0;
            for (auto node : component) {
                edges += adj[node].size();
            }
            edges /= 2;
            if (edges == vertices * (vertices - 1) / 2) {
                count++;
            }
        }
        return count;
    }
};