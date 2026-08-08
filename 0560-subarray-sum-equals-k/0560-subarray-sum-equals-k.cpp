class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int prefix=0;
        int complement=0;
        mp[0]=1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            complement=prefix-k;
            if(mp.find(complement)!=mp.end()){
                count+=mp[complement];
            }
            mp[prefix]++;
        }
        return count;
    }
};