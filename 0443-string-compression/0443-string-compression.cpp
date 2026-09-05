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
            ans.push_back(curr);
            if(count>1){
                string temp=to_string(count);
                for(auto c:temp) ans.push_back(c);
            }
        }
        chars=ans;
        return chars.size();
    }
};