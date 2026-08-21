class Solution {
private:
    int solve(int i,vector<int>& nums,vector<int>& dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int inc=nums[i]+solve(i+2,nums,dp);
        int excl=solve(i+1,nums,dp);
        return dp[i]=max(inc,excl);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int ans=solve(0,nums,dp);
        return ans;    
    }
};