class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 4;
        int ans=0;
        int i=2;
        while(2*i<=n){
            if(pow(2,i)<=n && n<pow(2,i+1)){
                ans=pow(2,i+1);
            }
            i++;
        }
    return ans;
    }
};