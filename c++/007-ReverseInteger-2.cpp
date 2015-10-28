#include<iostream>
using namespace std;

#define MAX_NUM INT_MAX
#define MIN_NUM INT_MIN

typedef int t_num;

class Solution {
public:
	t_num reverse(t_num x) {
        if (x <= MIN_NUM) return 0;
        t_num ans = 0, tmp = x < 0 ? -x : x;
        while (tmp > 0) {
            t_num lastDigit = tmp % 10;
            if (ans > (MAX_NUM - lastDigit) / 10) return 0;
            ans = ans * 10 + lastDigit;
            tmp /= 10;
        }
        return (x >= 0) ? ans : -ans;
    }
};

int main() {
	return 0;
}
