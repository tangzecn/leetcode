#include<iostream>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        if (n <= 0) return 0;
        return int(sqrt(n));
    }
};

int main() {
    return 0;
}