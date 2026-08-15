class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currmax=nums[0];
        int maxi=nums[0];
        int currmin=nums[0];
        int mini=nums[0];
        for(int i=1;i<nums.size();i++){
            currmax=max(nums[i],currmax+nums[i]);
            maxi=max(maxi,currmax);
        }
        for(int i=1;i<nums.size();i++){
            currmin=min(nums[i],currmin+nums[i]);
            mini=min(mini,currmin);
        }
        return max(abs(maxi),abs(mini));
    }
};