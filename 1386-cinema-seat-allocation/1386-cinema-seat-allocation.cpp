class Solution {
private:
    bool isvalid(set<int>& seats, int seat) {
        if(seats.find(seat) == seats.end()) return true;
        return false;
    }
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,set<int>>mp;
        for(int i=0;i<reservedSeats.size();i++){
            int u=reservedSeats[i][0];
            int v=reservedSeats[i][1];
            mp[u].insert(v);
        }
        int result=(n-mp.size())*2;
        for(auto& it:mp){
            set<int>& seats = it.second;
            bool groupA= isvalid(seats,2) && isvalid(seats,3) && isvalid(seats,4) && isvalid(seats,5);
            bool groupB= isvalid(seats,4) && isvalid(seats,5) && isvalid(seats,6) && isvalid(seats,7);
            bool groupC= isvalid(seats,6) && isvalid(seats,7) && isvalid(seats,8) && isvalid(seats,9);
            if(groupA && groupC) result+=2;
            else if(groupA || groupB || groupC) result+=1;
        }
        return result;
    }
};