class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while(s<e){
            long long int sum=nums[s]+nums[e];
            if(sum==target){
                return {s+1,e+1};
            }
            if(sum>target) e--;
            else s++;
        }
        return {};
    }
};