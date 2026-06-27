class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp;
        for(int i=0;i<text.length();i++){
            char ch=text[i];
            if(ch=='b' || ch=='a' || ch=='l' || ch=='o'|| ch=='n'){
                mp[ch]++;
            }
        }
        int count=0;
        while(mp['a']>=1 && mp['b']>=1 && mp['l']>=2 && mp['o']>=2 && mp['n']>=1){
            mp['a']--;
            mp['b']--;
            mp['l'] -= 2;
            mp['n']--;
            mp['o'] -= 2;
            count++;
        }
        return count;
    }
};