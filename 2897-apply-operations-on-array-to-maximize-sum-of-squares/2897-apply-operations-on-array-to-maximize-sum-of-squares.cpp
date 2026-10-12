class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int mod=1e9+7;
        vector<int>count(32,0);
        for(int &num:nums){
            for(int bit=0;bit<32;bit++){
                if(num & (1<<bit)){
                    count[bit]++;
                }
            }
        }
        long long result=0;
        while(k--){
            long long curr=0;
            for(int bit=0;bit<32;bit++){
                if(count[bit]>0){
                    count[bit]--;
                    curr=(curr | (1<<bit));
                }
            }
            result=(result+(curr*curr)) % mod;
        }
        return result;
    }
};