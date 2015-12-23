#include<iostream>
#include<queue>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    // BFS
    bool validTree(int n, vector<pair<int, int> >& edges) {
        if (n == 0 && edges.size() != 0) return false;
        if (n != 0 && edges.size() != n - 1) return false;
        
        vector<vector<int> > g(n);
        for (int i=0; i<edges.size(); i++) {
            int x = edges[i].first, y = edges[i].second;
            if (x < 0 || x >= n || y < 0 || y >= n) return false;
            if (x == y) return false;
            g[x].push_back(y); 
            g[y].push_back(x); 
        }
        
        unordered_set<int> visited;
        queue<std::pair<int, int> > nodes;
        nodes.push(std::make_pair(0, -1));
        while (!nodes.empty()) {
            int x = nodes.front().first;
            int parent = nodes.front().second;
            nodes.pop();
            
            visited.insert(x);
            for (int i=0; i<g[x].size(); i++) {
                int y = g[x][i];
                if (y == parent) continue;
                if (visited.find(y) != visited.end()) return false;
                nodes.push(std::make_pair(y, x));
            }
        }
    
        return visited.size() == n;
    }
};

int main() {
    return 0;
}
