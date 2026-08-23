class Solution {
public:
    bool sumGame(string nums) {
        int n=nums.length();
        int Rq=0;
        int Lq=0;
        int rightsum=0;
        int leftsum=0;
        for(int i=0;i<n/2;i++){
            if(nums[i]=='?'){
                Lq++;
            }else{
                leftsum+=nums[i]-'0';
            }
        }
        for(int i=n-1;i>=n/2;i--){
            if(nums[i]=='?'){
                Rq++;
            }else{
                rightsum+=nums[i]-'0';
            }
        }
        if((Lq+Rq)%2!=0) return true;
        int diff = leftsum - rightsum;
        diff += (Lq - Rq) / 2 * 9;
        if(diff!=0) return true;
        return false;
    }
};