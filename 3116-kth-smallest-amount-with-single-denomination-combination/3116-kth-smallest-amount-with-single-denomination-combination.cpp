class Solution {
public:
    typedef long long ll;
    ll countsmaller(ll mid,vector<int>& coins){
        ll correct=0;
        int n=coins.size();
        for(int exp=1;exp<(1<<n);exp++){
            ll lcm=0;
            ll order=0; //even or odd
            for(int i=0;i<n;i++){
                if(exp & (1<<i)){
                    order++; 
                    if(lcm==0){
                        lcm=coins[i];
                    }else{
                        lcm=lcm*coins[i]/gcd(lcm,coins[i]);
                    }
                }
            }
            if(order%2==0){
                correct-=mid/lcm;
            }else{
                correct+=mid/lcm;
            }
        }
        return correct;
    }
    ll findKthSmallest(vector<int>& coins, int k) {
        ll result=-1;
        ll l=1;
        ll r=1LL*(*max_element(coins.begin(),coins.end()))*k;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(countsmaller(mid,coins)>=k){
                result=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return result;
    }
};