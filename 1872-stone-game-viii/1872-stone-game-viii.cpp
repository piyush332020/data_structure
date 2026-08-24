class Solution {
// private:
//     int solve(int i,vector<int>&prefix,vector<int>& dp){
//         int n=prefix.size();
//         if(i==n-1){
//             return prefix[i];
//         }
//         if(dp[i]!=-1) return dp[i];
//         int take=prefix[i]-solve(i+1,prefix,dp);
//         int skip=solve(i+1,prefix,dp);
//         return dp[i]=max(take,skip);
//     }
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int>prefix;
        vector<int>dp(n,-1);
        long long int sum=0;
        for(int i=0;i<stones.size();i++){
            sum+=stones[i];
            prefix.push_back(sum);
        }
        dp[n-1]=prefix[n-1];
        for(int i=n-2;i>=1;i--){
            int take=prefix[i]-dp[i+1];
            int skip=dp[i+1];
            dp[i]=max(take,skip);
        }
        return dp[1];
    }
};