class DetectSquares {
public: 
    map<pair<int,int>,int> ptsCount;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        ptsCount[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int squares = 0;
        int x1 = point[0], y1 = point[1];
        for (auto &p : ptsCount) {
            int x3 = p.first.first, y3 = p.first.second;

            if (abs(x3 - x1) != abs(y3 - y1) || x3 == x1 || y3 == y1) continue;

            pair<int, int> p2 = {x1, y3}; // Top-left or bottom-left
            pair<int, int> p4 = {x3, y1}; // Top-right or bottom-right

            if (ptsCount.count(p2) && ptsCount.count(p4)) {
                squares += ptsCount[p2] * ptsCount[p4] * p.second;
            }
        }
        return squares;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */