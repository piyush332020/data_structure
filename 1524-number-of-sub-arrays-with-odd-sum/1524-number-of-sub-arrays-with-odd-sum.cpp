class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;
        long long prefix = 0;
        long long odd = 0, even = 1; 
        long long count = 0;

        for(int x : arr){
            prefix += x;

            if(prefix % 2 == 0){
                count += odd;
                even++;
            } else {
                count += even;
                odd++;
            }
        }

        return count % mod;
    }
};