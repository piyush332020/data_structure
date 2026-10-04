class Solution {
private:
    bool solve(int i,int open,int close,string& s,vector<vector<vector<int>>>& dp){
        if(i>=s.length()){
            if(open ==close) return true;
            return false;
        }
        if(close >open) return false;
        if(dp[i][open][close]!=-1) return dp[i][open][close];
        if(s[i]=='('){
            return dp[i][open][close]=solve(i+1,open+1,close,s,dp);
        }
        if(s[i]==')'){
            return dp[i][open][close]=solve(i+1,open,close+1,s,dp);
        }
        if(s[i]=='*'){
            return dp[i][open][close]=solve(i+1,open+1,close,s,dp) || solve(i+1,open,close+1,s,dp) || solve(i+1,open,close,s,dp);
        }
        
        return dp[i][open][close];
    }
public:
    bool checkValidString(string s) {
        int n=s.length();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        int open=0;
        int close=0;
        if(solve(0,open,close,s,dp)) return true;
        return false;
    }
};