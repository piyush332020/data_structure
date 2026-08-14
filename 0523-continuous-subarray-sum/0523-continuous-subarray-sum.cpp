class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int prefixsum=0;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            int rem=prefixsum % k;
            if(mp.count(rem)){
                if(i-mp[rem]>=2){
                    return true;
                }
            }else{
                mp[rem]=i;
            }
        }
        return false;
    }
};