#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    typedef vector<std::pair<int, int> > T_UNION_NODES;
   
    // Union-find algorithm 
    vector<int> numIslands2(int m, int n, vector<pair<int, int> >& positions) {
        const vector<int> MOVE_X = {-1, 1, 0, 0};
        const vector<int> MOVE_Y = {0, 0, -1, 1};
        // pair(parent, number_of_nodes_in_this_union)
        // The parent of root node equals to itself
        // number_of_nodes_in_this_union is only available for root node
        T_UNION_NODES nodes(m * n, std::make_pair(-1, 0));
        vector<int> res;
        int cnt_islands = 0;
        for (int i=0; i<positions.size(); i++) {
            int x = positions[i].first;
            int y = positions[i].second;
            int index = getIndex(x, y, m, n);
            // water position
            if (nodes[index].first < 0) {
                nodes[index].first = index;
                nodes[index].second = 1;
                cnt_islands++;
                for (int j=0; j<MOVE_X.size(); j++) {
                    int x1 = x + MOVE_X[j];
                    int y1 = y + MOVE_Y[j];
                    if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n) continue;
                    int index1 = getIndex(x1, y1, m, n);
                    // water position
                    if (nodes[index1].first < 0) continue;
                    if (merge(nodes, index, index1)) {
                        cnt_islands--;
                    }
                }
            }
            res.push_back(cnt_islands);
        }
        return res;
    }
    
private:
    int getIndex(const int x, const int y, const int m, const int n) {
        return x * n + y;
    }
    
    bool merge(T_UNION_NODES &nodes, int index1, int index2) {
        int root1 = findRoot(nodes, index1);
        int root2 = findRoot(nodes, index2);
        if (root1 == root2) return false;
        
        if (nodes[root1].second >= nodes[root2].second) {
            nodes[root1].second += nodes[root2].second;
            nodes[root2].first = root1;
            nodes[root2].second = 0;
        } else {
            nodes[root2].second += nodes[root1].second;
            nodes[root1].first = root2;
            nodes[root1].second = 0;
        }
        return true;
    }
    
    int findRoot(T_UNION_NODES &nodes, int index) {
        int root = index;
        while (nodes[root].first != root) {
            root = nodes[root].first;
        }
        int node = index;
        while (node != root) {
            int next_node = nodes[node].first;
            nodes[node].first = root;
            node = next_node;
        }
        return root;
    }
};

int main() {
    return 0;
}
