#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // Union Find
    int countComponents(int n, vector<pair<int, int> >& edges) {
        vector<int> parent(n, -1);
        int res = n;
        for (int i=0; i<edges.size(); i++) {
            int x = edges[i].first;
            int y = edges[i].second;
            int r_x = findRoot(parent, x);
            int r_y = findRoot(parent, y);
            if (r_x != r_y) {
                res--;
                if (parent[r_x] < parent[r_y]) {
                    parent[r_x] += parent[r_y];
                    parent[r_y] = r_x;
                } else {
                    parent[r_y] += parent[r_x];
                    parent[r_x] = r_y;
                }
            }
        }
        return res;
    }

private:
    int findRoot(vector<int> &parent, int x) {
        int root = x;
        while (parent[root] >= 0) {
            root = parent[root];
        }
        while (x != root) {
            int tmp_parent = parent[x];
            parent[x] = root;
            x = tmp_parent;
        }
        return root;
    }
};

int main() {
    return 0;
}
