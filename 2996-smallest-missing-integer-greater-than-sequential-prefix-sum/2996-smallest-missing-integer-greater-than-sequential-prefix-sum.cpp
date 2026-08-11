class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]+1==nums[i]){
                sum+=nums[i];
            }else{
                break;
            }
        }
        unordered_set<int> s(nums.begin(), nums.end());
        while(s.count(sum))
            sum++;

        return sum;
    }
};