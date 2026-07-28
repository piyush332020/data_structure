class Solution {
public:
    int balancedStringSplit(string s) {
        int countr=0;
        int countl=0;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='R') countr++;
            if(s[i]=='L') countl++;
            if(countl==countr) count++;
        }
        return count;
    }
};