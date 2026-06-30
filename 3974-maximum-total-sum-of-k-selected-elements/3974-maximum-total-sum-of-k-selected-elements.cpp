class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long int ans=0;
        for(int i=n-1;i>=0;i--){
            if(mul>0 && k>0){
                long long int num=1LL*nums[i]*mul;
                ans+=num;
                mul--;
                k--;
            }else{
                if(mul<=0 && k>0){
                    ans+=nums[i];
                    k--;
                }
            }
        }
        return ans;
    }
};