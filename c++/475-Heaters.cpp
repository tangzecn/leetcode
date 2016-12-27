#include<algorithm>
#include<climits>
#include<vector>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (heaters.size() == 0) {
            return INT_MAX ? houses.size() > 0 : 0;
        }
        
        std::sort(houses.begin(), houses.end());
        std::sort(heaters.begin(), heaters.end());
        int h_index = 0, res = 0;
        for (int i=0; i<houses.size(); i++) {
            while (h_index < heaters.size() && heaters[h_index] < houses[i]) {
                h_index++;
            }
            int radius = INT_MAX;
            if (h_index > 0) {
                radius = min(radius, houses[i] - heaters[h_index - 1]);
            }
            if (h_index < heaters.size()) {
                radius = min(radius, heaters[h_index] - houses[i]);
            }
            res = max(radius, res);
        }
        return res;
    }
};

int main() {
    return 0;
}
