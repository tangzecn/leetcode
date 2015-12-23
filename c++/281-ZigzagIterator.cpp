#include<vector>
using namespace std;

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        ptr.push_back(v1.begin()); tail.push_back(v1.end());
        ptr.push_back(v2.begin()); tail.push_back(v2.end());
        n = v1.size() + v2.size();
        index = 0;
    }

    int next() {
        if (n <= 0) return -1;
        while (ptr[index] == tail[index]) {
            index = (index + 1) % ptr.size();
        }
        n--;
        int res = *ptr[index];
        ptr[index]++;
        index = (index + 1) % ptr.size();
        return res;
    }

    bool hasNext() {
        return n > 0;
    }

private: 
    int n, index;
    vector<vector<int>::iterator> ptr, tail;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    return 0;
}