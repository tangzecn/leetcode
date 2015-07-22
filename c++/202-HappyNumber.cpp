#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) return false;
        unordered_set<int> mark;
        while (n != 1 && mark.find(n) == mark.end()) {
            mark.insert(n);
            int newN = 0;
            while (n > 0) {
                int digit = n % 10;
                newN += digit * digit;
                n /= 10;
            }
            n = newN;
        }
        return (n == 1);
    }
};

int main() {
    return 0;
}
