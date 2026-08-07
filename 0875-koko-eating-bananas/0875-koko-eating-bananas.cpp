class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int low=1;
        int high=piles[n-1];
        while(low<=high){
            int mid=low+(high-low)/2;
            int i=0;
            long long int count=0;
            for(int i = 0; i < piles.size(); i++) {
                count += (piles[i] + mid - 1) / mid;
            }
            if(count>h){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};