class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        nums[0]=1;
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(abs(nums[i-1]-nums[i])<=1){
                ans=max(ans,nums[i]);
            }else{
                int sum=nums[i-1]+1;
                nums[i]=sum;
                ans=max(sum,ans);
            }
        }
        return ans;
    }
};