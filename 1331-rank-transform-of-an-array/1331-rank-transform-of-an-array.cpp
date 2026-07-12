class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>copy=nums;
        vector<int>ans;
        sort(copy.begin(),copy.end());
        copy.erase(unique(copy.begin(),copy.end()),copy.end());
        int count=1;
        for(int i=0;i<copy.size();i++){
            mp[copy[i]]=count;
            count++;
        }
        for(int i=0;i<nums.size();i++){
            ans.push_back(mp[nums[i]]);
        }
        return ans;
    }
};