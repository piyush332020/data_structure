class Solution {
private:
    void solve(int n,int k,int start,vector<int>& sub,vector<vector<int>>& ans){
        if(sub.size()==k){
            ans.push_back(sub);
            return;
        }
        for(int i=start;i<=n;i++){
            sub.push_back(i);
            solve(n,k,i+1,sub,ans);
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int>sub;
        solve(n,k,1,sub,ans);
        return ans;    
    }
};