class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        long long int ans=0;
        int mod=1e9+7;
        for(int i=0;i<nums.size();i++){ 
            long long width = nums[i] % 10;

            long long digit = nums[i] / 10;
            long long temp = digit;
            long long total = 0;

            while(temp > 0) {
                total++;
                temp /= 10;
            }
            long long yDigits = total - width;
            long long j = 1;
            for(int k = 0; k < yDigits; k++) {
                j *= 10;
            }
            long long x = digit / j;
            long long y = digit % j;

            long long power = 1;

            while(y > 0) {
                if(y % 2 == 1) {
                    power = (power * x) % mod;
                }
                x = (x * x) % mod;
                y /= 2;
            }
            ans = (ans + power) % mod;
        }
        return ans%mod;
    }
};