#include<iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        num = removeFactor(num, 2);
        num = removeFactor(num, 3);
        num = removeFactor(num, 5);
        return num == 1;
    }

private:
    int removeFactor(int num, int factor) {
        while (num > 1 && num % factor == 0) {
            num /= factor;
        }
        return num;
    } 
};

int main() {
    return 0;
}
