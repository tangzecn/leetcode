#include<iostream>
#include<vector>
using namespace std;

class Vector2D {
public:
    Vector2D(vector<vector<int> >& vec2d) {
        row_iter = vec2d.begin(); row_end = vec2d.end();
        if (row_iter != row_end) {
            column_iter = row_iter->begin();
        }
        reachNext();
    }

    int next() {
        if (row_iter != row_end) {
            int res = *column_iter;
            column_iter++;
            reachNext();
            return res;
        } else {
            return -1;
        }
    }

    bool hasNext() {
        return row_iter != row_end;
    }

private:
    vector<vector<int> >::iterator row_iter, row_end;
    vector<int>::iterator column_iter;
    
    void reachNext() {
        while (row_iter != row_end && column_iter == row_iter->end()) {
            row_iter++;
            if (row_iter != row_end) {
                column_iter = row_iter->begin();
            }
        }
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    return 0;
}
