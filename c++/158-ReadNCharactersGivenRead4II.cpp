#include<iostream>
using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    Solution() {
        buffer_ptr = 0;
        buffer_len = 0;
        reach_end = false;
    }
    
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int data_len = 0;
        while (hasMoreData() && data_len < n) {
            while (buffer_ptr<buffer_len && data_len<n) {
                buf[data_len++] = buffer[buffer_ptr++];
            }
            if (!reach_end && buffer_ptr >= buffer_len) {
                buffer_ptr = 0;
                buffer_len = read4(buffer);
                reach_end = buffer_len < MAX_BUFFER_LEN;
            }
        }
        return data_len;        
    }
    
private:
    static const int MAX_BUFFER_LEN = 4;
    char buffer[MAX_BUFFER_LEN];
    int buffer_ptr;
    int buffer_len;
    bool reach_end;

    bool hasMoreData() {
        return !reach_end || buffer_ptr < buffer_len;
    }
};

int main() {
    return 0;
}