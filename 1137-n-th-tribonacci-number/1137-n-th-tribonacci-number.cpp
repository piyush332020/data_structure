class Solution {
public:
    int tribonacci(int n) {
        int ans=0;
        vector<int>fib(38);
        fib[0]=0;
        fib[1]=1;
        fib[2]=1;
        for(int i=3;i<38;i++){
            fib[i]=fib[i-3]+fib[i-2]+fib[i-1];
        }
        return fib[n];
    }
};