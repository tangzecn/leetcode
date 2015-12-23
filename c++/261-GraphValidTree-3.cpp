#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // Union-Find, no need to copy the edges, less space usage
    bool validTree(int n, vector<pair<int, int> >& edges) {
        if (n == 0 && edges.size() != 0) return false;
        if (n != 0 && edges.size() != n - 1) return false;
        
        vector<int> parent(n, -1);
        for (int i=0; i<edges.size(); i++) {
            int x = edges[i].first, y = edges[i].second;
            if (x < 0 || x >= n || y < 0 || y >= n) return false;
            if (x == y) return false;
            
            int root_x = findRoot(x, parent);
            int root_y = findRoot(y, parent);
            if (root_x == root_y) return false;
            if (parent[root_x] < parent[root_y]) {
                parent[root_x] += parent[root_y];
                parent[root_y] = root_x;
            } else {
                parent[root_y] += parent[root_x];
                parent[root_x] = root_y;
            }
        }
        
        return true;
    }
    
private:
    int findRoot(int x, vector<int> &parent) {
        int root = x;
        while (parent[root] >= 0) root = parent[root];
        while (x != root) {
            int temp = parent[x];
            parent[x] = root;
            x = temp;
        }
        return root;
    }
};

int main() {
    return 0;
}
