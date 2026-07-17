class Solution {
private:
    void dfs(int node,int parent,int& timer,vector<int>& visited,vector<int>& desc,vector<int>& low,vector<vector<int>>& result,vector<vector<int>>& adj){

        visited[node]=1;
        desc[node]=low[node]=timer++;
        for(auto num:adj[node]){
            if(num==parent){
                continue;
            }
            if(!visited[num]){
                dfs(num,node,timer,visited,desc,low,result,adj);
                low[node]=min(low[num],low[node]);
                //check bridge
                if(low[num]>desc[node]){
                    vector<int>ans;
                    ans.push_back(node);
                    ans.push_back(num);
                    result.push_back(ans);
                }
            }else{
                //back age
                low[node]=min(low[node],desc[num]);
            }
        }

    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto e:connections){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>disc(n,-1);
        vector<int>low(n,-1);
        int parent=-1;
        int timer=0;
        vector<int>visited(n,0);
        vector<vector<int>>result;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,parent,timer,visited,disc,low,result,adj);
            }
        }
        return result;
    }
};