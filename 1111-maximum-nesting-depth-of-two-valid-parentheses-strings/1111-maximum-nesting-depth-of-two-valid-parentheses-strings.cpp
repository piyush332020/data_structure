class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>ans;
        int count=-1;
        for(int i=0;i<seq.length();i++){
            if(seq[i]=='('){
                count++;
                ans.push_back(count%2);
            }
            else{
                ans.push_back(count%2);
                count--;
            }
        }
        return ans;
    }
};