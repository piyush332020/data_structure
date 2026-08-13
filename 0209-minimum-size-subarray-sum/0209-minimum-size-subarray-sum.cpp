class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int len=INT_MAX;
        int sum=0;
        for(int right=0;right<n;right++){
            sum+=nums[right];
            while(sum>=target){
                len=min(len,right-left+1);
                sum-=nums[left];
                left++;
            }
        }
        if(len==INT_MAX) return 0;
        return len;
    }
};