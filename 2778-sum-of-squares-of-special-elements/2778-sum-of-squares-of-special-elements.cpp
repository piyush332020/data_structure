class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n=nums.size();
        long long int sum=0;
        for(int i=0;i<nums.size();i++){
            int index=i+1;
            if(n % index == 0){
                sum+=nums[i]*nums[i];
            }
        }
        return sum;
    }
};