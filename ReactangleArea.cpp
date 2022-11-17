class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

        int AreaOfA = (ax2-ax1)*(ay2-ay1);
        int AreaOfB= (bx2-bx1)*(by2-by1);

        int overlapR =0;

        // x overlap.
        int xoverlap = min(ax2,bx2) - max(ax1,bx1);
        int yoverlap = min(ay2,by2) - max(ay1,by1);

        if(xoverlap>0 && yoverlap>0)
        overlapR = xoverlap*yoverlap;

        return AreaOfA+AreaOfB-overlapR;


    }
};
