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

struct pairhash {
public:
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U> &x) const {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int n = points.size();
        int ans = 0;
        unordered_map<pair<long long, long long>, int, pairhash> countMap;
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
                if (deltax < 0) {
                    deltax = -deltax;
                    deltay = -deltay;
                }
                
                if (deltax == 0) {
                    deltay = 1;
                } else
                if (deltay == 0) {
                    deltax = 1;
                } else {
                    long long gcdxy = gcd(deltax, deltay);
                    deltax /= gcdxy;
                    deltay /= gcdxy;
                }
                
                pair<long long, long long> key = make_pair(deltax, deltay);
                if (countMap.find(key) == countMap.end()) {
                    countMap[key] = 1;
                } else {
                    countMap[key]++;
                }
            }  
            if (countMap.size() == 0) {
                ans = max(ans, duplicates);
            } else {
                for (unordered_map<pair<long long, long long>, int, pairhash>::iterator it = countMap.begin(); 
                     it != countMap.end(); it++) {
                    ans = max(ans, it->second + duplicates);
                }
            }
        }
        return ans;
    }
    
    long long gcd(long long x, long long y) {
        x = llabs(x); y = llabs(y);
        long long z;
        do {
            z = x % y;
            x = y;
            y = z;
        } while (z != 0);
        return x;
    }
};

int main() {
	return 0;
}
