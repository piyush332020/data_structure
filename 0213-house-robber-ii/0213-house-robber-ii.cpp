class Solution {
private:
    int includelast(int i,vector<int>& nums,vector<int>& dp1){
        if(i<=0) return 0;
        if(dp1[i]!=-1) return dp1[i];
        int inc=nums[i]+includelast(i-2,nums,dp1);
        int excl=includelast(i-1,nums,dp1);
        return dp1[i]=max(inc,excl);
    }
    int excludelast(int i,vector<int>& nums,vector<int>& dp2){
        if(i<0) return 0;
        if(dp2[i]!=-1) return dp2[i];
        int inc=nums[i]+excludelast(i-2,nums,dp2);
        int excl=excludelast(i-1,nums,dp2);
        return dp2[i]=max(inc,excl);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1) return nums[0];
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        int ans=max(includelast(n-1,nums,dp1),excludelast(n-2,nums,dp2));
        return ans;
    }
};