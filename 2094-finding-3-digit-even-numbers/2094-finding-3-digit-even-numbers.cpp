class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int>mp;
        vector<int>ans;
        int count=0;
        for(int i=0;i<digits.size();i++){
            for(int j=0;j<digits.size();j++){
                for(int k=0;k<digits.size();k++){
                    if(j==k || k==i || j==i){
                        continue;
                    }else{
                        int digit=100*digits[i]+10*digits[j]+digits[k];
                        if(digit % 2 == 0 && digits[i]!=0 && mp.find(digit)==mp.end()){
                            count++;
                            ans.push_back(digit);
                            mp[digit]=1;
                        }
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};