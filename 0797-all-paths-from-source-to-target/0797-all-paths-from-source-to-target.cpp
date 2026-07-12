class Solution {
private:
    void dfs(int node,vector<int>& component,vector<vector<int>>& graph,vector<vector<int>>& ans){
        component.push_back(node);
        if(node==graph.size()-1){
            ans.push_back(component);
            component.pop_back();
            return;
        }
        for(auto num:graph[node]){
            dfs(num,component,graph,ans);
        }
        component.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>component;
        dfs(0,component,graph,ans);
        return ans;
    }
};