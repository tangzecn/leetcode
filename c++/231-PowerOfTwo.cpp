#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && (((n - 1) & n) == 0);    
    }
};

int main() {
	return 0;
}