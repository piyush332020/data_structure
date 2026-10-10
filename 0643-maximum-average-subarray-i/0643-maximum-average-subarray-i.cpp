class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        double ans=sum;
        int left=0;
        for(int i=k;i<nums.size();i++){
            sum+=nums[i];
            sum-=nums[left];
            ans=max(ans,sum);
            left++;
        }
        return ans/k;
    }
};