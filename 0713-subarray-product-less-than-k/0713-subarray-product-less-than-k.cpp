class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0;
        int left=0;
        if(k<=1) return 0;
        long long int product=1;
        for(long long int i=0;i<nums.size();i++){
            product*=nums[i];
            while(product>=k){
                product/=nums[left];
                left++;
            }
            if(product<=k) count+=i-left+1;
        }
        return count;
    }
};