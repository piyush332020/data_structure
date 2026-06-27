class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        if (nums.size() < 4) return {};
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-3;i++){
            for(int j=i+1;j<nums.size()-2;j++){
                int left=j+1;
                int right=nums.size()-1;
                while(left<right){
                   long long  int sum=1LL * nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                    }
                    else if(sum<target) left++;
                    else right--;
                }
            }
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};