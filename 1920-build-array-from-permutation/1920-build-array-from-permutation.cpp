class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int>arr;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int j=nums[i];
            arr.push_back(nums[j]);
        }
        return arr;
    }
};