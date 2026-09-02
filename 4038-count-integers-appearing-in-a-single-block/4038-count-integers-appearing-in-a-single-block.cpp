class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int count=0;
        for(auto &it:mp){          // for ex:          2->[1,2]
            if(it.second.size()==1){         //        ^   ^
                count++;                     //        |   |
            }else{                           // it.first   it.second
                bool isspecial=true;
                for(int i=1;i<it.second.size();i++){
                    if(it.second[i-1]+1!=it.second[i]){
                        isspecial=false;
                    }
                }
                if(isspecial){
                    count++;
                }
            }
        }
        return count;
    }
};