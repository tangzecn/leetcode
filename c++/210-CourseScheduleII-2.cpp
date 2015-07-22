#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // DFS
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        if (numCourses <= 0) return vector<int>();
        
        vector<vector<int> > graph(numCourses, vector<int>(0, 0));
        for (int i=0; i<prerequisites.size(); i++) {
            int x = prerequisites[i].second;
            int y = prerequisites[i].first;
            if (x == y) return vector<int>();
            graph[x].push_back(y);
        }
        
        vector<bool> visited(numCourses, false);
        vector<bool> inStack(numCourses, false);
        vector<int> res;
        for (int i=0; i<numCourses; i++) {
            if (!visited[i] && !dfs(i, graph, visited, inStack, res)) return vector<int>();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

private:
    bool dfs(int x, const vector<vector<int> > &graph, vector<bool> &visited, vector<bool> &inStack, vector<int> &res) {
        if (inStack[x]) return false;
        inStack[x] = true;
        for (int i=0; i<graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited[y] && !dfs(y, graph, visited, inStack, res)) return false;
        }
        inStack[x] = false;
        visited[x] = true;
        res.push_back(x);
        return true;
    }
};

int main() {
    return 0;
}
