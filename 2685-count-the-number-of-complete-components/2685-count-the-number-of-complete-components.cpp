class Solution {
private:
    void dfs(int node, vector<int>& visited, vector<int>& component,vector<vector<int>>& adj){
        visited[node] = 1;
        component.push_back(node);
        for (auto num : adj[node]) {
            if (!visited[num]) {
                dfs(num, visited, component, adj);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges){
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, visited, component, adj);
                int vertices = component.size();
                int edgeCount = 0;
                for (auto node : component) {
                    edgeCount += adj[node].size();
                }
                edgeCount /= 2;

                if (edgeCount == vertices * (vertices - 1) / 2) {
                    count++;
                }
            }
        }
        return count;
    }
};