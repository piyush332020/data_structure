class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(char w:word){
            mp[w]++;
        }
        vector<pair<char,int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](pair<char,int> a, pair<char,int> b){
            return a.second < b.second;  
        });
        int n=mp.size();
        long long int ans=0;;
        for(auto& it:v){
            if(n<=8){
                ans+=it.second;
            }
            if(n>8 && n<=16){
                ans+=it.second*2;
            }
            if(n>16 && n<=24){
                ans+=it.second*3;
            }
            if(n>24 && n<=26){
                ans+=it.second*4;
            }
            n--;
        }
        return ans;
    }
};