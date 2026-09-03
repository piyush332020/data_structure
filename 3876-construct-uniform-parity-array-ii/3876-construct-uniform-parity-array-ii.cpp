class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int countodd=0;
        int counteven=0;
        int minval=nums1[0];
        for(int i:nums1){
            if(i<minval) minval=i;
        }
        if(minval%2!=0)return true;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=0) return false;
        }
        return true;
    }
};