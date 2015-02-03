#include<iostream>
#include<unordered_map>
#include<utility>
#include<vector>
using namespace std;

// Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int n = points.size();
        int ans = 0;
        unordered_map<double, int> countMap;
        for (int i=0; i<n; i++) {
            int duplicates = 0;
            countMap.clear();
            for (int j=0 ; j<n; j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    duplicates++;
                    continue;
                }
                
                long long deltax = (long long)points[i].x - points[j].x;
                long long deltay = (long long)points[i].y - points[j].y;
                double key;
                if (deltay != 0) {
                    key = (double)deltax / (double)deltay;
                } else {
                    key = std::numeric_limits<double>::infinity();
                }
                if (countMap.find(key) == countMap.end()) {
                    countMap[key] = 1;
                } else {
                    countMap[key]++;
                }
            } 
            
            if (countMap.size() == 0) {
                ans = max(ans, duplicates);
            } else {
                for (unordered_map<double, int>::iterator it = countMap.begin(); 
                     it != countMap.end(); it++) {
                    ans = max(ans, it->second + duplicates);
                }
            }
        }
        return ans;
    }
};

int main() {
	return 0;
}