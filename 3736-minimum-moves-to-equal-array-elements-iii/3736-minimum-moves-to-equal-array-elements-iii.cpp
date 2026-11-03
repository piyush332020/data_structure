class Solution {
public:
    int minMoves(vector<int>& nums) {
        int i;
        int ans=0;
        int maxEle=*max_element(nums.begin(),nums.end());

        for(i=0;i<nums.size();i++)
        {
            int diff=maxEle-nums[i];

            ans=ans+diff;
        }
        return ans;
    }
};