class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char>ans;
        int i=0;
        while(i<chars.size()){
            char curr =chars[i];
            int count=0;
            while(i<chars.size() && curr==chars[i]){
                count++;
                i++;
            }
            if(count>1){
                ans.push_back(curr);
                string temp=to_string(count);
                for(auto c:temp) ans.push_back(c);
            }else{
                ans.push_back(curr);
            }
        }
        chars=ans;
        return chars.size();
    }
};