class Solution {
public:
    long long countCommas(long long n) {
        long long int count=0;
        if(n<1000) return 0;
        for(long long int i=1000;i<=n;i*=1000){
            count +=(n-i+1);
            if(n/1000<i)break;
        }
        return count;
    }
};