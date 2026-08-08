class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(auto &it:mp){
            if(it.second.size()>=2){
                int ans=0;
                for(int i = 1; i < it.second.size(); i++) {
                    int ans = abs(it.second[i-1]-it.second[i]);
                    if(ans <= k) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};