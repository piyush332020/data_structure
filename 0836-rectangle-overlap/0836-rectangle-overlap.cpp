class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1=rec1[2];
        int y1=rec1[3];
        int x2=rec2[0];
        int y2=rec2[1];
        int x11=rec1[0];
        int y11=rec1[1];
        int x22=rec2[2];
        int y22=rec2[3];
        if (x11 >= x22 || x2 >= x1) {
            return false;
        }
        if (y11 >= y22 || y2 >= y1) {
            return false;
        }
        return true;
    }
};