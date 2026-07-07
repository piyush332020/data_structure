class Solution {
public:
    long long sumAndMultiply(long long int n) {
        string s = to_string(n);
        long long int ans=0;
        long long int sum=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!='0'){
                sum+=s[i]-'0';
                ans=ans*10+(s[i]-'0');
            }
        }
        return ans*sum;
    }   
};