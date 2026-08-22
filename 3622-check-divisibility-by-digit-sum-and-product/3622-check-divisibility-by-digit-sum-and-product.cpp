class Solution {
public:
    bool checkDivisibility(int n) {
        long long int add=0;
        long long int mul=1;
        int temp=n;
        while(n!=0){
            int digit=n%10;
            add+=digit;
            mul*=digit;
            n/=10;
        }
        if(temp%(mul+add)==0) return true;
        return false;
    }
};