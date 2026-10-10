class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int>diff;
        unordered_map<int,int>mp;
        long long total=(long long)k1+k2;
        long long int sum=0;
        for(int i=0;i<nums1.size();i++){
            int diffrence=abs(nums1[i]-nums2[i]);
            diff.push_back(diffrence);
            sum+=diffrence;
            mp[diffrence]++;
        }
        if (total >= sum) return 0;
        sort(diff.begin(),diff.end());
        int maxi=diff.back();
        for(int i=maxi;i>0 && total>0;i--){
            int cnt=min(total,(long long )mp[i]);
            mp[i]-=cnt;
            mp[i-1]+=cnt;
            total-=cnt;
        }
        long long ans=0;
        for(auto &it:mp){
            ans+=1LL*it.second*it.first*it.first;
        }
        return ans;
    }
};