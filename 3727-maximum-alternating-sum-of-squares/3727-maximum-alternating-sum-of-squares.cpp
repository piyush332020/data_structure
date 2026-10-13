class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=(long long)(nums[i]*nums[i]);
        }
        sort(nums.begin(),nums.end());
        long long front=0;
        for(int i=0;i<nums.size()/2;i++){
            front+=nums[i];
        }
        long long back=0;
        for(int i=nums.size()/2;i<nums.size();i++){
            back+=nums[i];
        }
        return back-front;
    }
};