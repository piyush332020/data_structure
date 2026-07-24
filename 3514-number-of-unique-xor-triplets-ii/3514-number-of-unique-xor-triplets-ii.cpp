class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>twoele;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                int result=nums[i]^nums[j];
                twoele.insert(result);
            }
        }
        unordered_set<int>ans;
        for(auto num:twoele){
            for(int i=0;i<nums.size();i++){
                ans.insert(num^nums[i]);
            }
        }
        return ans.size();
    }
};