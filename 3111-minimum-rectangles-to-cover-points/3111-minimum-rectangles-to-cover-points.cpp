class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        // make an sorted array of x axis points as y co ordinates do not matter
        vector<int> xPoints;
        for(auto point: points) {
            xPoints.push_back(point[0]);
        }
        sort(xPoints.begin(), xPoints.end());
        
        // keep making block of size w (maximum), as it will help to minimize number of rectangles
        int start = -(1e9+1);
        int numberOfRectangeles = 0;
        for(auto point: xPoints) {
            if(point <= start + w) {
                continue; // skip this point, as it will be inclued in current block
            }
            start = point; // start a new block (rectangle)
            numberOfRectangeles++;
        }
        
        return numberOfRectangeles;
    }
};