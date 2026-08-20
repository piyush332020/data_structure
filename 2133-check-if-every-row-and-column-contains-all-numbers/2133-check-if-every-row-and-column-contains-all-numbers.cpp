class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            unordered_map<int,int>mp;
            for(int j=0;j<matrix.size();j++){
                mp[matrix[i][j]]++;
            }
            for(auto it:mp){
                if(it.second>1) return false;
            }
        }
        for(int i=0;i<matrix.size();i++){
            unordered_map<int,int>mp;
            for(int j=0;j<matrix.size();j++){
                mp[matrix[j][i]]++;
            }
            for(auto it:mp){
                if(it.second>1) return false;
            }
        }
        return true;
    }
};