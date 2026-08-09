class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discount) {
        sort(prices.begin(),prices.end());
        sort(discount.begin(),discount.end());
        int p=prices.size()-1;
        int d=discount.size()-1;
        double ans=0;
        int count=discount.size();
        for(int i=0;i<prices.size();i++){
            double temp=0;
            if(count!=0){
                temp=prices[p-i]*(100-discount[d-i])/100.0;
                ans+=temp;
                count--;
            }else{
                ans+=prices[p-i];
            }
        }
        return ans;
    }
};