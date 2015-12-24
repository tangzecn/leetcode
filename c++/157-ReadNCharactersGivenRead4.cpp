#include<iostream>
using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int cnt = 0;
        bool reach_end = false;
        char temp[4];
        while (cnt < n && !reach_end) {
            int temp_n = read4(temp);
            reach_end = temp_n < 4;
            for (int i=0; i<temp_n && cnt<n; i++) {
                buf[cnt] = temp[i];
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    return 0;
}