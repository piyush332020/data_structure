class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<int> indegree(n,0);
        for(auto e:invocations){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int>suspicious(n,false);
        queue<int>q;
        q.push(k);
        suspicious[k]=true;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto &ngbr:adj[front]){
                indegree[ngbr]--;
                if(!suspicious[ngbr]){
                    q.push(ngbr);
                    suspicious[ngbr]=true;
                }
            }
        }
        vector<int>ans(n);
        vector<int>result;
        bool notremove=false;
        for(int i=0;i<n;i++){
            if(suspicious[i] && indegree[i]>0){
                notremove=true;
                break;
            }
            if(!suspicious[i]){
                result.push_back(i);
            }
        }
        if(notremove){
            for(int i=0;i<n;i++){
                ans[i]=i;
            }
            return ans;
        }
        return result;
    }
};