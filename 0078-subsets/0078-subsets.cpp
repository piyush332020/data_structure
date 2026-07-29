class Solution {
private:
    void solve(vector<int>&nums,vector<int> sub,int index,vector<vector<int>>& ans){
        if(index>=nums.size()){
            ans.push_back(sub);
            return; 
        }
        solve(nums,sub,index+1,ans);
        int num=nums[index];
        sub.push_back(num);
        solve(nums,sub,index+1,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>sub;
        solve(nums,sub,0,ans);
        return ans;
    }
};