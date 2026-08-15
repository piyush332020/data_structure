class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currmax=nums[0];
        int maxi=nums[0];
        int currmin=nums[0];
        int mini=nums[0];
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        for(int i=1;i<nums.size();i++){
            //find maxsum;
            currmax=max(nums[i],currmax+nums[i]);
            maxi=max(currmax,maxi);

            //find minimum
            currmin=min(nums[i],currmin+nums[i]);
            mini=min(currmin,mini);
        }
        if(maxi<0){
            return maxi;
        }
        return max(maxi, total - mini);
    }
};