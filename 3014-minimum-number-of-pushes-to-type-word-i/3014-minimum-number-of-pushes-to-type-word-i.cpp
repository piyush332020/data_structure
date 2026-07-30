class Solution {
public:
    int minimumPushes(string word) { 
        int n=word.size();
        if(n<=8) return n;
        if(n>16 && n<=24) return 3*n-24;
        if(n>8 && n<=16) return 2*n-8;
        if(n==25) return 52;
        if(n==26) return 56;
        return -1;
    }
};