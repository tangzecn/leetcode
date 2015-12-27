// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n < 1) return 0;
        int left = 1, right = n;
        while (left < right) {
            int mid = (left & right) + ((left ^ right) >> 1);
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
    return 0;
}