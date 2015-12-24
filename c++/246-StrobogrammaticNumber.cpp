#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int i = 0, j = num.size() - 1;
        while (i <= j) {
            if (!match(num[i], num[j])) return false;
            i++; j--;
        }
        return true;
    }

private:
    bool match(const char x, const char y) {
        return (x == '6' && y == '9') ||
               (x == '9' && y == '6') ||
               (x == '0' && y == '0') || 
               (x == '1' && y == '1') ||
               (x == '8' && y == '8');
    }
};

int main() {
    return 0;
}