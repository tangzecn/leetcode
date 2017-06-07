#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i=-0; i<flowerbed.size(); i++) {
            if ((flowerbed[i] == 0) && 
                (i == 0 || flowerbed[i - 1] == 0) && 
                (i + 1 == flowerbed.size() || flowerbed[i + 1]  == 0)) {
                n--;
                flowerbed[i] = 1;
            } 
        }
        return n <= 0;
    }
};

int main() {
  return 0;
}
