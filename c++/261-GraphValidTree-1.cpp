#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // DFS
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
        
        vector<bool> visited(n, false);
        if (!hasCycle(-1, 0, visited, g)) return false;
        for (int i=0; i<n; i++)
            if (!visited[i]) return false;
        return true;
    }
    
private:
    bool hasCycle(int last_node, int curr_node, vector<bool> &visited, const vector<vector<int> > &g) {
        visited[curr_node] = true;
        for (int i=0; i<g[curr_node].size(); i++) {
            int next_node = g[curr_node][i];
            if (next_node != last_node) {
                if (visited[next_node]) return false;
                if (!hasCycle(curr_node, next_node, visited, g)) return false;
            }
        }
        return true;
    }
};

int main() {
    return 0;
}
