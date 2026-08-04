class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<int>st(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=nums[0]+1;i<nums.back();i++){
            if(st.count(i)==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};