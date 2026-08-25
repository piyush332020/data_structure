class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto num:nums){
            mp[num]++;
        }
        int n=k;
        while(mp.find(n)!=mp.end()){
            n+=k;
        }
        return n;
    }
};