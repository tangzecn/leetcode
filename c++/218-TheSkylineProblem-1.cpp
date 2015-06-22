#include<vector>
#include<set>
using namespace std;

class Solution {
private:
    enum POINT_TYPE {LEFT, RIGHT};
    struct TPoint {
        int x, height;
        POINT_TYPE type;
        TPoint(int x_, int height_, POINT_TYPE type_): x(x_), height(height_), type(type_) {}
    };
    
    class TComp {
        public :
            bool operator() (const TPoint &x, const TPoint &y) {
                if (x.x != y.x) return x.x < y.x;
                else if (x.type != y.type) return x.type == LEFT;
                else return x.height < y.height;
            }
    };
    
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        vector<TPoint> points;
        for (int i=0; i<buildings.size(); i++) {
            points.push_back(TPoint(buildings[i][0], buildings[i][2], LEFT));
            points.push_back(TPoint(buildings[i][1], buildings[i][2], RIGHT));
        }
        sort(points.begin(), points.end(), TComp());
        
        int i = 0, lastHeight = 0;
        vector<pair<int, int> > res;
        multiset<int> heightSet;
        heightSet.insert(0);
        while (i < points.size()) {
            int curr_x = points[i].x;
            while (i < points.size() && points[i].x == curr_x) {
                if (points[i].type == LEFT) {
                    heightSet.insert(points[i].height);
                } else {
                    heightSet.erase(heightSet.find(points[i].height));
                }
                i++;
            }
            int currHeight = *(heightSet.rbegin());
            if (currHeight != lastHeight) {
                res.push_back(make_pair(curr_x, currHeight));
                lastHeight = currHeight;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
