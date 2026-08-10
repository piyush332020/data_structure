class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0;
        int end=intervals[0][1];
        if(intervals.size()<2) return 0;
        for(int i=1;i<intervals.size();i++){
            int s1=intervals[i][0];
            int e1=intervals[i][1];
            if(s1<end){
                count+=1;
                end = min(end, e1);
            }else{
                end=e1;
            }
        }
        return count;
    }
};